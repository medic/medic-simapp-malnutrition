
#include "polynomial.h"

#ifdef __AVR__

/**
 * @name polynomial_read_float:
 */
float polynomial_read_float(const float *p) {

  float rv;

  for (unsigned int i = 0; i < sizeof(float); ++i) {
    ((uint8_t *) &rv)[i] = rb((uint8_t *) p + i);
  }

  return rv;
}

#endif /* __AVR__ */

/**
 * @name polynomial_evaluate:
 */
boolean_t polynomial_evaluate(polynomial_result_t *result,
                              const polynomial_t *p,
                              const polynomial_domain_point_t x) {

  polynomial_domain_point_t d0 =
    _polynomial_domain_point_read(p->domain[0]);

  polynomial_domain_point_t d1 =
    _polynomial_domain_point_read(p->domain[1]);

  if (x < d0 || d1 < x) {
    return FALSE; /* Not defined here */
  }

  polynomial_result_t xn = x;
  polynomial_result_t rv = _polynomial_coefficient_read(p->coeff[0]);

  #ifndef POLYNOMIAL_FIXED_FN_DEGREE
    uint8_t degree = _polynomial_degree_read(p->degree);
  #else
    uint8_t degree = POLYNOMIAL_FIXED_FN_DEGREE;
  #endif

  for (unsigned int d = 1; d <= degree; ++d) {
    rv += _polynomial_coefficient_read(p->coeff[d]) * xn;
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
                                       polynomial_domain_point_t *n) {
  if (nr_identifiers <= 0) {
    return FALSE;
  }

  #ifndef POLYNOMIAL_FIXED_NR_TABLE_IDENTIFIERS
    if (nr_identifiers > _polynomial_nr_read(t->nr_identifiers)) {
      return FALSE;
    }
  #else
    if (nr_identifiers > POLYNOMIAL_FIXED_NR_TABLE_IDENTIFIERS) {
      return FALSE;
    }
  #endif

  /* Check entry identifiers */
  for (unsigned int i = 0; i < nr_identifiers; ++i) {
    if (_polynomial_identifier_read(t->id[i]) != id[i]) {
      return FALSE;
    }
  }

  /* Check domain */
  if (n) {

    polynomial_domain_point_t d0 =
      _polynomial_domain_point_read(t->fn.domain[0]);

    polynomial_domain_point_t d1 =
      _polynomial_domain_point_read(t->fn.domain[1]);

    if (*n < d0 || d1 < *n) {
      return FALSE;
    }
  }

  return TRUE;
}

/**
 * @name polynomial_is_table_terminator:
 */
boolean_t polynomial_is_table_terminator(const polynomial_table_entry_t *t) {

  polynomial_domain_point_t d0 =
    _polynomial_domain_point_read(t->fn.domain[0]);

  polynomial_domain_point_t d1 =
    _polynomial_domain_point_read(t->fn.domain[1]);

  return (d0 == 0 && d1 == 0);
}

/**
 * @name polynomial_table_find:
 */
const polynomial_table_entry_t *
  polynomial_table_find(const polynomial_table_entry_t *t,
                        uint8_t nr_identifiers,
                        polynomial_table_id_t *id,
                        polynomial_domain_point_t *n) {

  for (; !polynomial_is_table_terminator(t); t++) {
    if (polynomial_table_entry_match(t, nr_identifiers, id, n)) {
      return t;
    }
  }

  return NULL;
}

