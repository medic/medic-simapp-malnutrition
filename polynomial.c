
#include "polynomial.h"

/**
 * @name polynomial_evaluate:
 */
boolean_t polynomial_evaluate(polynomial_result_t *result,
                              const polynomial_t *p,
                              const polynomial_range_point_t x) {

  if (x < p->range[0] || p->range[1] < x) {
    return FALSE; /* Not defined here */
  }

  polynomial_result_t xn = x;
  polynomial_result_t rv = p->coeff[0];

  #ifndef POLYNOMIAL_FIXED_FN_DEGREE
    uint8_t degree = p->degree;
  #else
    uint8_t degree = POLYNOMIAL_FIXED_FN_DEGREE;
  #endif

  for (unsigned int d = 1; d <= degree; ++d) {
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
                                       polynomial_table_id_t *id,
                                       polynomial_range_point_t *n) {
  if (nr_identifiers <= 0) {
    return FALSE;
  }

  #ifndef POLYNOMIAL_FIXED_NR_TABLE_IDENTIFIERS
    if (nr_identifiers > t->nr_identifiers) {
      return FALSE;
    }
  #else
    if (nr_identifiers > POLYNOMIAL_FIXED_NR_TABLE_IDENTIFIERS) {
      return FALSE;
    }
  #endif

  /* Check entry identifiers */
  for (unsigned int i = 0; i < nr_identifiers; ++i) {
    if (t->id[i] != id[i]) {
      return FALSE;
    }
  }

  /* Check range */
  if (n) {
    if (*n < t->fn.range[0] || t->fn.range[1] < *n) {
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
                        polynomial_table_id_t *id,
                        polynomial_range_point_t *n) {

  for (; t->fn.range[0] > 0 || t->fn.range[1] > 0; t++) {
    if (polynomial_table_entry_match(t, nr_identifiers, id, n)) {
      return t;
    }
  }

  return NULL;
}

