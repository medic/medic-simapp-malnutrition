
#include <stdio.h>
#include <assert.h>
#include "datetime.h"

int main(int argc, char *argv[]) {

  int32_t result;
  boolean_t valid;
  stk_datetime_t t1, t2;

  /* Simple */
  valid = stk_set_datetime(&t1, 2015, 5, 28, 11, 48);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2015, 5, 29, 11, 48);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 1);

  valid = stk_set_datetime(&t1, 2015, 1, 1, 0, 0);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2014, 1, 1, 0, 0);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == -365);

  valid = stk_set_datetime(&t1, 2000, 1, 1, 0, 0);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2001, 1, 1, 0, 0);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 366);

  valid = stk_set_datetime(&t1, 1982, 1, 1, 5, 30);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2015, 5, 28, 14, 50);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 12200);

  valid = stk_set_datetime(&t1, 1982, 1, 1, 5, 30);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2015, 5, 28, 4, 50);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 12199);

  valid = stk_set_datetime(&t1, 0, 1, 1, 0, 0);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2015, 5, 28, 0, 0);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 736110);

  valid = stk_set_datetime(&t1, 1, 1, 1, 0, 0);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2015, 5, 28, 0, 0);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 735745);

  valid = stk_set_datetime(&t1, 2010, 9, 3, 3, 0);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2015, 5, 28, 3, 0);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 1728);

  /* Time handling */
  valid = stk_set_datetime(&t1, 2000, 1, 1, 5, 40);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2000, 1, 2, 5, 0);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 0);

  valid = stk_set_datetime(&t1, 2000, 1, 1, 5, 0);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2000, 1, 2, 5, 0);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 1);

  valid = stk_set_datetime(&t1, 2000, 1, 1, 5, 0);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2000, 1, 2, 15, 0);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 1);

  valid = stk_set_datetime(&t1, 2000, 1, 1, 5, 30);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2000, 1, 2, 5, 0);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 0);

  valid = stk_set_datetime(&t1, 2000, 1, 1, 5, 0);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2000, 1, 2, 5, 30);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 1);

  valid = stk_set_datetime(&t1, 2000, 1, 2, 5, 0);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2000, 1, 1, 5, 40);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 0);

  valid = stk_set_datetime(&t1, 2000, 1, 2, 5, 0);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2000, 1, 1, 5, 0);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == -1);

  valid = stk_set_datetime(&t1, 2000, 1, 2, 15, 0);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 2000, 1, 1, 5, 0);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == -1);

  valid = stk_set_datetime(&t1, 0, 1, 2, 5, 0);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 0, 1, 1, 15, 0);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 0);

  valid = stk_set_datetime(&t1, 0, 1, 2, 1, 5);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 0, 1, 1, 1, 15);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 0);

  valid = stk_set_datetime(&t1, 0, 1, 1, 1, 5);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 0, 1, 2, 1, 15);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == 1);

  valid = stk_set_datetime(&t1, 0, 1, 2, 1, 15);
  assert(valid == TRUE);
  valid = stk_set_datetime(&t2, 0, 1, 1, 1, 5);
  assert(valid == TRUE);
  valid = stk_subtract_datetime(&result, &t2, &t1);
  assert(valid == TRUE); assert(result == -1);

  return 0;
}

