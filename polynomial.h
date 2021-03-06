
#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#ifdef __AVR__
  #include <turbo/turbo.h>
#else
  #include <stdlib.h>
#endif

#include <math.h>
#include <inttypes.h>
#include "util.h"

/**
 * @name AVR compatibility macros:
 */
#ifdef __AVR__

  /**
   * @name polynomial_read_float:
   */
  float polynomial_read_float(const float *p);

  /* AVR flash memory implementation */
  #define _polynomial_nr_read(x) ((uint8_t) rb(&(x)))
  #define _polynomial_degree_read(x) ((uint8_t) rb(&(x)))
  #define _polynomial_identifier_read(x) ((int8_t) rb(&(x)))
  #define _polynomial_domain_point_read(x) ((int16_t) rw(&(x)))
  #define _polynomial_coefficient_read(x) polynomial_read_float(&(x))

#else

  /* Normal C implementation */
  #define _polynomial_nr_read(x) (x)
  #define _polynomial_degree_read(x) (x)
  #define _polynomial_identifier_read(x) (x)
  #define _polynomial_coefficient_read(x) (x)
  #define _polynomial_domain_point_read(x) (x)

#endif

/**
 * @name polynomial_result_t:
 */
typedef float polynomial_result_t;

/**
 * @name polynomial_input_t:
 */
typedef float polynomial_input_t;

/**
 * @name polynomial_coefficient_t:
 */
typedef float polynomial_coefficient_t;

/**
 * @name polynomial_domain_point_t:
 */
typedef int16_t polynomial_domain_point_t;

/**
 * @name polynomial_table_id_t:
 */
typedef int8_t polynomial_table_id_t;

/**
 * @name polynomial_fn_max_degree:
 */
#ifdef POLYNOMIAL_FIXED_FN_DEGREE
  #define POLYNOMIAL_FN_MAX_DEGREE \
    (POLYNOMIAL_FIXED_FN_DEGREE)
#else
  #ifndef POLYNOMIAL_FN_MAX_DEGREE
    #define POLYNOMIAL_FN_MAX_DEGREE (6)
  #endif
#endif

/**
 * @name polynomial_max_table_identifiers:
 */
#ifdef POLYNOMIAL_FIXED_NR_TABLE_IDENTIFIERS
    #define POLYNOMIAL_MAX_TABLE_IDENTIFIERS \
      (POLYNOMIAL_FIXED_NR_TABLE_IDENTIFIERS)
#else
  #ifndef POLYNOMIAL_MAX_TABLE_IDENTIFIERS
    #define POLYNOMIAL_MAX_TABLE_IDENTIFIERS (4)
  #endif
#endif

/**
 * @name polynomial_t:
 */
typedef struct polynomial {
  #ifndef POLYNOMIAL_FIXED_FN_DEGREE
    uint8_t degree;
  #endif
  polynomial_domain_point_t domain[2];
  polynomial_coefficient_t coeff[POLYNOMIAL_FN_MAX_DEGREE + 1];
} polynomial_t;

/**
 * @name polynomial_table_entry_t:
 */
typedef struct polynomial_table_entry {
  #ifndef POLYNOMIAL_FIXED_NR_TABLE_IDENTIFIERS
    uint8_t nr_identifiers;
  #endif
  polynomial_table_id_t id[POLYNOMIAL_MAX_TABLE_IDENTIFIERS];
  polynomial_t fn;
} polynomial_table_entry_t;


/**
 * @name polynomial_table_end:
 */
#ifdef POLYNOMIAL_FIXED_FN_DEGREE
  #ifdef POLYNOMIAL_FIXED_NR_TABLE_IDENTIFIERS
    #define POLYNOMIAL_TABLE_END \
      { {}, { { 0, 0 }, {} } }
  #else
    #define POLYNOMIAL_TABLE_END \
      { 0, {}, { { 0, 0 }, {} } }
  #endif
#else
  #ifdef POLYNOMIAL_FIXED_NR_TABLE_IDENTIFIERS
    #define POLYNOMIAL_TABLE_END \
      { {}, { 0, { 0, 0 }, {} } }
  #else
    #define POLYNOMIAL_TABLE_END \
      { 0, {}, { 0, { 0, 0 }, {} } }
  #endif
#endif

/**
 * @name polynomial_evaluate:
 */
boolean_t polynomial_evaluate(polynomial_result_t *result,
                              const polynomial_t *p,
                              const polynomial_input_t x);

/**
 * @name polynomial_table_entry_match:
 */
boolean_t polynomial_table_entry_match(const polynomial_table_entry_t *t,
                                       uint8_t nr_identifiers,
                                       polynomial_table_id_t *id,
                                       polynomial_domain_point_t *n);

/**
 * @name polynomial_is_table_terminator:
 */
boolean_t polynomial_is_table_terminator(const polynomial_table_entry_t *t);

/**
 * @name polynomial_table_find:
 */
const polynomial_table_entry_t *
  polynomial_table_find(const polynomial_table_entry_t *t,
                        uint8_t nr_identifiers,
                        polynomial_table_id_t *id,
                        polynomial_domain_point_t *n);

#endif /* __POLYNOMIAL_H__ */

