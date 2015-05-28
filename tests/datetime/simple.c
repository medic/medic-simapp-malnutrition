
#include <assert.h>
#include "datetime.h"

int main(int argc, char *argv[]) {

  boolean_t valid;
  stk_datetime_t t;

  /* Simple */
  valid = stk_set_datetime(&t, 2015, 5, 28, 11, 48);
  assert(valid == TRUE);
  
  valid = stk_set_datetime(&t, 2015, 5, 28, 0, 0);
  assert(valid == TRUE);
  
  valid = stk_set_datetime(&t, 0, 1, 1, 0, 0);
  assert(valid == TRUE);
  
  valid = stk_set_datetime(&t, 0, 0, 0, 0, 0);
  assert(valid == FALSE);

  /* Leap years */
  valid = stk_set_datetime(&t, 2015, 2, 29, 0, 0);
  assert(valid == FALSE);

  valid = stk_set_datetime(&t, 1600, 2, 29, 0, 0);
  assert(valid == TRUE);

  valid = stk_set_datetime(&t, 1800, 2, 29, 0, 0);
  assert(valid == FALSE);

  valid = stk_set_datetime(&t, 1900, 2, 29, 0, 0);
  assert(valid == FALSE);

  valid = stk_set_datetime(&t, 2000, 2, 29, 0, 0);
  assert(valid == TRUE);

  /* Month portion */
  valid = stk_set_datetime(&t, 2015, 1, 1, 0, 0);
  assert(valid == TRUE);
  
  valid = stk_set_datetime(&t, 2015, 13, 1, 0, 0);
  assert(valid == FALSE);
  
  valid = stk_set_datetime(&t, 2015, 0, 1, 0, 0);
  assert(valid == FALSE);

  valid = stk_set_datetime(&t, 2015, 1, 31, 0, 0);
  assert(valid == TRUE);

  valid = stk_set_datetime(&t, 2015, 2, 28, 0, 0);
  assert(valid == TRUE);

  valid = stk_set_datetime(&t, 2015, 3, 31, 0, 0);
  assert(valid == TRUE);

  valid = stk_set_datetime(&t, 2015, 4, 30, 0, 0);
  assert(valid == TRUE);

  valid = stk_set_datetime(&t, 2015, 5, 31, 0, 0);
  assert(valid == TRUE);

  valid = stk_set_datetime(&t, 2015, 6, 30, 0, 0);
  assert(valid == TRUE);

  valid = stk_set_datetime(&t, 2015, 7, 31, 0, 0);
  assert(valid == TRUE);

  valid = stk_set_datetime(&t, 2015, 8, 31, 0, 0);
  assert(valid == TRUE);

  valid = stk_set_datetime(&t, 2015, 9, 30, 0, 0);
  assert(valid == TRUE);

  valid = stk_set_datetime(&t, 2015, 10, 31, 0, 0);
  assert(valid == TRUE);

  valid = stk_set_datetime(&t, 2015, 11, 30, 0, 0);
  assert(valid == TRUE);

  valid = stk_set_datetime(&t, 2015, 12, 31, 0, 0);
  assert(valid == TRUE);

  /* Day portion */
  valid = stk_set_datetime(&t, 2015, 1, 0, 0, 0);
  assert(valid == FALSE);
  
  valid = stk_set_datetime(&t, 2015, 1, 32, 0, 0);
  assert(valid == FALSE);
  
  valid = stk_set_datetime(&t, 2015, 1, 31, 0, 0);
  assert(valid == TRUE);
  
  valid = stk_set_datetime(&t, 2015, 2, 28, 0, 0);
  assert(valid == TRUE);

  valid = stk_set_datetime(&t, 2015, 3, 31, 0, 0);
  assert(valid == TRUE);

  valid = stk_set_datetime(&t, 2015, 4, 30, 0, 0);
  assert(valid == TRUE);

  valid = stk_set_datetime(&t, 2015, 4, 31, 0, 0);
  assert(valid == FALSE);

  return 0;
}

