
#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <math.h>
#include <stdlib.h>
#include <inttypes.h>
#include "util.h"

/**
 * @name polynomial_result_t:
 */
typedef float polynomial_result_t;

/**
 * @name coefficient_t:
 */
typedef polynomial_result_t polynomial_coefficient_t;

/**
 * @name polynomial_range_point_t:
 */
typedef int16_t polynomial_range_point_t;

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
typedef struct {
  #ifndef POLYNOMIAL_FIXED_FN_DEGREE
    uint8_t degree;
  #endif
  polynomial_range_point_t range[2];
  polynomial_coefficient_t coeff[POLYNOMIAL_FN_MAX_DEGREE + 1];
} polynomial_t;

/**
 * @name polynomial_table_entry_t:
 */
typedef struct {
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
boolean_t polynomial_evaluate(float *result,
                              polynomial_t *p,
                              polynomial_range_point_t x);

/**
 * @name polynomial_table_entry_match:
 */
boolean_t polynomial_table_entry_match(const polynomial_table_entry_t *t,
                                       uint8_t nr_identifiers,
                                       polynomial_table_id_t *id);

/**
 * @name polynomial_table_find:
 */
const polynomial_table_entry_t *
  polynomial_table_find(const polynomial_table_entry_t *t,
                        uint8_t nr_identifiers,
                        polynomial_table_id_t *id);

#endif /* __POLYNOMIAL_H__ */

