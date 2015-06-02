
#ifndef __GRADE_H__
#define __GRADE_H__

#ifdef __AVR__
  #include <turbo/turbo.h>
#else
  #include <stdlib.h>
#endif

#include <math.h>
#include <string.h>
#include <inttypes.h>
#include "polynomial.h"

/**
 * @name grade_nr_minimum:
 */
#define GRADE_NR_MINIMUM (-4)

/**
 * @name grade_nr_maximum:
 */
#define GRADE_NR_MAXIMUM (4)

/**
 * @name grade_levels_total:
 */
#if (GRADE_NR_MAXIMUM < GRADE_NR_MINIMUM)
  #error GRADE_NR_MAXIMUM cannot be less than GRADE_NR_MINIMUM
#endif

#define GRADE_NR_TOTAL \
  ((GRADE_NR_MAXIMUM) - (GRADE_NR_MINIMUM) + 1)

/**
 * @name grade_result_t:
 */
typedef struct grade_result {
  int8_t grade;
  uint8_t between[2];
  float grade_interpolated;
  polynomial_result_t values[GRADE_NR_TOTAL];
} grade_result_t;

/**
 * @name grade_calculate:
 */
boolean_t grade_calculate(grade_result_t *result,
                          const polynomial_table_entry_t *t,
                          uint8_t nr_identifiers,
                          polynomial_table_id_t *id,
                          polynomial_domain_point_t x,
                          polynomial_result_t input);


#endif /* __GRADE_H__ */

