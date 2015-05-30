
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
 * @name polynomial_table_identifier_t:
 */
typedef int8_t polynomial_table_identifier_t;

/**
 * @name polynomial_fn_max_degree:
 */
#ifndef POLYNOMIAL_FN_MAX_DEGREE
  #define POLYNOMIAL_FN_MAX_DEGREE (6)
#endif

/**
 * @name polynomial_max_table_entry_identifiers:
 */
#ifndef POLYNOMIAL_MAX_TABLE_ENTRY_IDENTIFIERS
  #define POLYNOMIAL_MAX_TABLE_ENTRY_IDENTIFIERS (4)
#endif

/**
 * @name polynomial_t:
 */
typedef struct {
  uint8_t degree;
  polynomial_range_point_t range[2];
  polynomial_coefficient_t coeff[POLYNOMIAL_FN_MAX_DEGREE + 1];
} polynomial_t;

/**
 * @name polynomial_table_entry_t:
 */
typedef struct {
  uint8_t nr_identifiers;
  polynomial_table_identifier_t id[POLYNOMIAL_MAX_TABLE_ENTRY_IDENTIFIERS];
  polynomial_t fn;
} polynomial_table_entry_t;


/**
 * @name polynomial_table_end:
 */
#define POLYNOMIAL_TABLE_END \
  { 0, {}, { 0, { 0, 0 }, {} } }

/**
 * @name polynomial_evaluate:
 */
boolean_t polynomial_evaluate(float *result,
                              polynomial_t *p,
                              polynomial_range_point_t x);

/**
 * @name polynomial_table_entry_match:
 */
boolean_t polynomial_table_entry_match(polynomial_table_entry_t *t,
                                       uint8_t nr_identifiers,
                                       polynomial_table_identifier_t *id);

#endif /* __POLYNOMIAL_H__ */

