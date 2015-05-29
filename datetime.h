
#ifndef __DATETIME_H__
#define __DATETIME_H__

#ifdef __AVR__
  #include <turbo/turbo.h>
#endif /* __AVR__ */

#include <stdlib.h>
#include <inttypes.h>
#include "util.h"

/**
 * @name stk_datetime_t:
 */
typedef struct {
  uint16_t year;
  uint8_t month;
  uint8_t day;
  uint8_t hour;
  uint8_t minute;
} stk_datetime_t;

/**
 * @name stk_datetime_info_t:
 */
typedef struct {
  uint8_t century;
  uint8_t pivot;
} stk_datetime_info_t;

/**
 * @name decode_bcd:
 *   Extract a two-decimal-digit number from the one-byte
 *   binary-coded-decimal input `in`. Place the result in
 *   the eight-bit result value pointed to by `result`.
 */
boolean_t decode_bcd(uint8_t *result, uint8_t in);

/**
 * @name decode_bcd_uint16:
 *   Extract a two-decimal-digit number from the one-byte
 *   binary-coded-decimal input `in`. Place the result in
 *   the sixteen-bit result value pointed to by `result`.
 */
boolean_t decode_bcd_uint16(uint16_t *result, uint8_t in);

/**
 * @name stk_retrieve_current_datetime:
 *   Retrieve the current *local* date and time as an `stk_datetime_t`.
 *   If compiling for AVR, this uses the Bladox SIM Application Toolkit
 *   library to fetch date/time information directly from the mobile
 *   equipment (ME). If compiling for a normal Unix-ish system, this
 *   function uses `gettimeofday` and `localtime`.
 */
boolean_t stk_retrieve_current_datetime(stk_datetime_t *result,
                                        stk_datetime_info_t *info);

/**
 * @name stk_set_datetime:
 *   Set all components of `t` based upon the provided arguments.
 *   Return TRUE if the resulting datetime object refers to a valid
 *   date and time, or FALSE otherwise.
 */
boolean_t stk_set_datetime(stk_datetime_t *t, uint16_t y,
                           uint8_t m, uint8_t d, uint8_t hh, uint8_t mm);

/**
 * @name stk_validate_datetime:
 *   Returns TRUE if the components of `t` represent a valid
 *   Gregorian calendar date and time; otherwise return FALSE.
 */
boolean_t stk_validate_datetime(stk_datetime_t *t);

/**
 * @name stk_calculate_datetime_day_number:
 *   Calculate the day number of the date in `t`. January 1st
 *   of the year zero (1 BCE) is day zero.
 */
boolean_t stk_calculate_datetime_day_number(int32_t *result,
                                            stk_datetime_t *t);

/**
 * @name stk_subtract_datetime:
 *   Subtract the stk_datetime_t value `t1` from `t2`, and place the
 *   answer in `result`. The `result` variable is expressed as a signed
 *   integer number of calendar days. Returns TRUE if `result` was set,
 *   or FALSE if the difference could not be computed.
 */
boolean_t stk_subtract_datetime(int32_t *result,
                                stk_datetime_t *t2, stk_datetime_t *t1);

#endif /* __DATETIME_H__ */

