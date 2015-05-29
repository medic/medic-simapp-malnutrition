
/* Raise limits */
#define POLYNOMIAL_FN_MAX_DEGREE (16)

#include <assert.h>
#include "polynomial.h"

int main(int argc, char *argv[]) {

  boolean_t valid;
  polynomial_result_t result;

  /* Simple */
  polynomial_t p1 = { 2, { 1, 10 }, { 1, 2, 3 } };

  valid = polynomial_evaluate(&result, &p1, 0);
  assert(valid == FALSE);

  valid = polynomial_evaluate(&result, &p1, 11);
  assert(valid == FALSE);

  valid = polynomial_evaluate(&result, &p1, 1);
  assert(valid == TRUE); assert(result == 6.0);

  valid = polynomial_evaluate(&result, &p1, 10);
  assert(valid == TRUE); assert(result == 321.0);

  /* Trivial equation */
  polynomial_t p2 = { 0, { 1, 1000 }, { 4 } };

  valid = polynomial_evaluate(&result, &p2, 500);
  assert(valid == TRUE); assert(result == 4.0);

  /* Linear equation */
  polynomial_t p3 = { 1, { 1, 1000 }, { 10, 20 } };

  valid = polynomial_evaluate(&result, &p3, 5);
  assert(valid == TRUE); assert(result == 110.0);

  /* Powers of two */
  polynomial_t p4 = { 11, { 2, 2 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

  valid = polynomial_evaluate(&result, &p4, 2);
  assert(valid == TRUE); assert(result == 4095.0);

  return 0;
}

