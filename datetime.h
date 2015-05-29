
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
 */
boolean_t decode_bcd(uint8_t *result, uint8_t in);

/**
 * @name decode_bcd_uint16:
 */
boolean_t decode_bcd_uint16(uint16_t *result, uint8_t in);

/**
 * @name retrieve_current_time:
 */
#if defined __AVR__
  boolean_t stk_retrieve_current_time(stk_datetime_t *result,
                                      stk_datetime_info_t *info);
#endif /* defined __AVR__ */

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
 * @name stk_calculate_day_number:
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

