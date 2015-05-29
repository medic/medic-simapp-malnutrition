
#include "polynomial.h"

/**
 * @name polynomial_evaluate:
 */
boolean_t polynomial_evaluate(float *result,
                              polynomial_t *p,
                              polynomial_range_point_t x) {

  if (x < p->range[0] || p->range[1] < x) {
    return FALSE; /* Not defined here */
  }

  polynomial_result_t xn = x;
  polynomial_result_t rv = p->coeff[0];

  for (unsigned int d = 1; d <= p->degree; ++d) {
    rv += p->coeff[d] * xn;
    xn *= x;
  }

  *result = rv;
  return TRUE;
};

