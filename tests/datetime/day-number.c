
#include <stdio.h>
#include <assert.h>
#include "datetime.h"

int main(int argc, char *argv[]) {

  int32_t result;
  boolean_t valid;
  stk_datetime_t t;

  /* Simple */
  valid = stk_set_datetime(&t, 2015, 5, 28, 11, 48);
  assert(valid == TRUE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 736110);

  valid = stk_set_datetime(&t, 2015, 5, 29, 0, 0);
  assert(valid == TRUE);

  /* Year zero */
  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 736111);

  valid = stk_set_datetime(&t, 0, 0, 0, 0, 0);
  assert(valid == FALSE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == FALSE);

  valid = stk_set_datetime(&t, 0, 1, 1, 0, 0);
  assert(valid == TRUE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 0);

  valid = stk_set_datetime(&t, 0, 1, 2, 0, 0);
  assert(valid == TRUE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 1);

  valid = stk_set_datetime(&t, 0, 2, 1, 0, 0);
  assert(valid == TRUE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 31);

  valid = stk_set_datetime(&t, 0, 2, 28, 0, 0);
  assert(valid == TRUE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 58);

  valid = stk_set_datetime(&t, 0, 2, 29, 0, 0);
  assert(valid == TRUE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 59);

  valid = stk_set_datetime(&t, 0, 3, 1, 0, 0);
  assert(valid == TRUE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 60);

  valid = stk_set_datetime(&t, 0, 12, 31, 0, 0);
  assert(valid == TRUE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 365);

  /* Large year numbers */
  valid = stk_set_datetime(&t, 65535, 12, 31, 0, 0);
  assert(valid == TRUE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 23936530);

  valid = stk_set_datetime(&t, 65535, 12, 30, 0, 0);
  assert(valid == TRUE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 23936529);

  valid = stk_set_datetime(&t, 65535, 1, 1, 0, 0);
  assert(valid == TRUE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 23936166);

  valid = stk_set_datetime(&t, 65534, 1, 1, 0, 0);
  assert(valid == TRUE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 23935801);

  valid = stk_set_datetime(&t, 65533, 1, 1, 0, 0);
  assert(valid == TRUE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 23935436);

  /* Leap years */
  valid = stk_set_datetime(&t, 65532, 1, 1, 0, 0);
  assert(valid == TRUE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 23935070);

  valid = stk_set_datetime(&t, 4, 2, 29, 0, 0);
  assert(valid == TRUE);

  valid = stk_calculate_datetime_day_number(&result, &t);
  assert(valid == TRUE); assert(result == 1519);

  return 0;
}

