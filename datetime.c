
#include "datetime.h"

#ifndef __AVR__
  #include <time.h>
  #include <sys/time.h>
#endif /* !defined __AVR__ */

/**
 * @name decode_bcd:
 *   Extract a two-decimal-digit number from the one-byte
 *   binary-coded-decimal input `in`. Place the result in
 *   the eight-bit result value pointed to by `result`.
 */
boolean_t decode_bcd(uint8_t *result, uint8_t in) {

  uint8_t low = (in & 0xf);
  uint8_t high = (in & 0xf0) >> 4;

  if (low > 9 || high > 9) {
    return FALSE;
  }

  *result = (low * 10) + high;
  return TRUE;
}

/**
 * @name _stk_compare_datetime_times:
 *   Compare only the time portions of `t1` and `t2`, ignoring the
 *   date portion entirely. Return 0 if the two times are equal,
 *   -1 if `t1` is greater, and 1 if `t2` is greater.
 */
static int _stk_compare_datetime_times(stk_datetime_t *t1,
                                       stk_datetime_t *t2) {

  return (
    (t1->hour == t2->hour)
      ? ((t1->minute == t2->minute) ? 0
          : (t1->minute > t2->minute ? -1 : 1))
      : (t1->hour > t2->hour ? -1 : 1)
  );
}

/**
 * @name stk_retrieve_current_datetime:
 *   Retrieve the current *local* date and time as an `stk_datetime_t`.
 *   If compiling for AVR, this uses the Bladox SIM Application Toolkit
 *   library to fetch date/time information directly from the mobile
 *   equipment (ME). If compiling for a normal Unix-ish system, this
 *   function uses `gettimeofday` and `localtime`.
 */
#if defined __AVR__
boolean_t stk_retrieve_current_datetime(stk_datetime_t *result,
                                    stk_datetime_info_t *info) {

  stk_datetime_info_t default_datetime_info = {
    .century = 19, .pivot = 71
  };

  if (!info) {
    info = &default_datetime_info;
  }

  uint8_t *res = provide_date();
  uint16_t j = get_tag (res, T_DATE);

  if (j == 0) {
    return FALSE; /* Tag not found */
  }

  size_t len = res[j + 1];
  uint8_t *data = &res[j + 2];
   
  if (len < 5) {
    return FALSE; /* Incomplete data */
  }

  /* Decode each component:
   *  If anything isn't valid binary-coded-decimal,
   *  fail the whole operation by returning false. */

  uint8_t year;

  if (!decode_bcd(&year, data[0])) {
    return FALSE;
  }

  result->year = (uint16_t) year;

  if (!decode_bcd(&result->month, data[1])) {
    return FALSE;
  }

  if (!decode_bcd(&result->day, data[2])) {
    return FALSE;
  }
  
  if (!decode_bcd(&result->hour, data[3])) {
    return FALSE;
  }
  
  if (!decode_bcd(&result->minute, data[4])) {
    return FALSE;
  }


  /* Add century to year */
  result->year += (
    (result->year >= info->pivot ?
      info->century : info->century + 1) * 100
  );

  /* Success */
  return TRUE;
}
#else
boolean_t stk_retrieve_current_datetime(stk_datetime_t *result,
                                        stk_datetime_info_t *info) {

  struct tm tm;
  struct timeval tv;

  if (gettimeofday(&tv, NULL) < 0) {
    return FALSE;
  }

  if (localtime_r(&tv.tv_sec, &tm) == NULL) {
    return FALSE;
  }

  result->year = tm.tm_year;
  result->month = tm.tm_mon + 1;
  result->day = tm.tm_mday;
  result->hour = tm.tm_hour;
  result->minute = tm.tm_min;

  return TRUE;
}
#endif /* defined __AVR__ */


#if !defined __AVR__
/**
 * @name stk_set_datetime:
 *   Set all components of `t` based upon the provided arguments.
 *   Return TRUE if the resulting datetime object refers to a valid
 *   date and time, or FALSE otherwise.
 */
boolean_t stk_set_datetime(stk_datetime_t *t, uint16_t y,
                           uint8_t m, uint8_t d, uint8_t hh, uint8_t mm) {

  t->year = y;
  t->month = m;
  t->day = d;
  t->hour = hh;
  t->minute = mm;

  return stk_validate_datetime(t);
}
#endif /* ! ddefined __AVR__ */

/**
 * @name stk_validate_datetime:
 *   Returns TRUE if the components of `t` represent a valid
 *   Gregorian calendar date and time; otherwise return FALSE.
 */
boolean_t stk_validate_datetime(stk_datetime_t *t) {
  
  if (t->hour > 23) {
    return FALSE;
  }

  if (t->minute > 59) {
    return FALSE;
  }

  /* Month is one-based */
  if (t->month <= 0 || t->month > 12) {
    return FALSE;
  }

  /* Day is one-based */
  if (t->day <= 0) {
    return FALSE;
  }

  /* Days per month */
  uint8_t day_map[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };

  /* Days in selected month */
  uint8_t total_days = day_map[t->month];

  /* Handle February */
  if (t->month == 2) {
    boolean_t is_leap_year = (
      (t->year % 4 == 0) &&
        !(t->year % 100 == 0 && t->year % 400 != 0)
    );
    if (is_leap_year) {
      total_days = 29;
    }
  }

  if (t->day > total_days) {
    return FALSE;
  }

  return TRUE;
}

/**
 * @name stk_calculate_datetime_day_number:
 *   Calculate the day number of the date in `t`. January 1st
 *   of the year zero (1 BCE) is day zero.
 */
boolean_t stk_calculate_datetime_day_number(int32_t *result,
                                            stk_datetime_t *t) {

  if (!stk_validate_datetime(t)) {
    return FALSE;
  }

  /* Integer overflow note:
      We're using a signed integer here for convenience, but
      don't worry - even with a 32-bit year, it wouldn't overflow
      until after the year 5,883,516, at which point you'd probably
      be dead. We have a 16-bit year, so overflow should be impossible. */

  int32_t month = (t->month + 9) % 12;
  int32_t year = t->year - (month / 10);

  *result = (
    (365 * year) + (t->day - 1)
      + ((month * 306 + 5) / 10) /* Move origin to March 1st */
      + (year / 4) - (year / 100) + (year / 400) /* Handle leap years */
  );

  /* Move origin back:
      This moves the origin back to January 1st, taking care to
      count the extra leap-year day in year zero if necessary. */

  *result += 59;

  if (t->year == 0 && t->month >= 3) {
    *result += 1;
  }

  return TRUE;
}

/**
 * @name stk_subtract_datetime:
 *   Subtract the stk_datetime_t value `t1` from `t2`, and place the
 *   answer in `result`. The `result` variable is expressed as a signed
 *   integer number of calendar days. Returns TRUE if `result` was set,
 *   or FALSE if the difference could not be computed.
 */
boolean_t stk_subtract_datetime(int32_t *result,
                                stk_datetime_t *t2, stk_datetime_t *t1) {

  int32_t day1, day2;

  if (!stk_calculate_datetime_day_number(&day2, t2)) {
    return FALSE;
  }
  
  if (!stk_calculate_datetime_day_number(&day1, t1)) {
    return FALSE;
  }

  /* Date portion */
  *result = day2 - day1;

  /* Time portion */
  boolean_t is_positive = (*result > 0);
  int comparison = _stk_compare_datetime_times(t2, t1);

  if (comparison > 0) {
    if (is_positive) {
      *result -= 1;
    }
  } else if (comparison < 0) {
    if (!is_positive) {
      *result += 1;
    }
  }

  return TRUE;
}

