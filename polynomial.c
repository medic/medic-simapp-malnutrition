
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

/**
 * @name polynomial_table_entry_match:
 */
boolean_t polynomial_table_entry_match(const polynomial_table_entry_t *t,
                                       uint8_t nr_identifiers,
                                       polynomial_table_id_t *id) {

  if (nr_identifiers <= 0 || nr_identifiers > t->nr_identifiers) {
    return FALSE;
  }

  for (unsigned int i = 0; i < nr_identifiers; ++i) {
    if (t->id[i] != id[i]) {
      return FALSE;
    }
  }

  return TRUE;
}

/**
 * @name polynomial_table_find:
 */
const polynomial_table_entry_t *
  polynomial_table_find(const polynomial_table_entry_t *t,
                        uint8_t nr_identifiers,
                        polynomial_table_id_t *id) {

  for (; t->nr_identifiers > 0; t++) {
    if (polynomial_table_entry_match(t, nr_identifiers, id)) {
      return t;
    }
  }

  return NULL;
}

