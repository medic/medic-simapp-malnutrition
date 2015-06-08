
#include "grade.h"

/**
 * @name grade_calculate:
 */
boolean_t grade_calculate(grade_result_t *result,
                          const polynomial_table_entry_t *t,
                          uint8_t nr_identifiers,
                          polynomial_table_id_t *id,
                          polynomial_input_t x,
                          polynomial_result_t y) {

  const polynomial_table_entry_t *e = t;
  polynomial_table_id_t grade = GRADE_NR_MINIMUM;

  if (nr_identifiers <= 0) {
    return FALSE;
  }

  /* Clear target */
  memset(result, '\0', sizeof(*result));

  /* Evaluate each curve */
  unsigned int i = 0;
  polynomial_domain_point_t xi = x;

  while (grade <= GRADE_NR_MAXIMUM) {

    id[nr_identifiers - 1] = grade;
    e = polynomial_table_find(e, nr_identifiers, id, &xi);

    if (!e) {
      return FALSE; /* Missing curve */
    }

    if (!polynomial_evaluate(&result->values[i], &e->fn, x)) {
      return FALSE; /* Shouldn't happen */
    }

    ++grade; ++i;
  }

  /* Find input's curve between-ness */
  for (i = 0; i < GRADE_NR_TOTAL; ++i) {
    if (result->values[i] >= y) {
      break;
    }
  }

  /* Save results */
  result->between[1] = i;
  result->between[0] = (i > 0 ? i - 1 : i);
  result->grade = (GRADE_NR_MINIMUM - 1) + i;

  /* Low-end saturation */
  if (result->grade < GRADE_NR_MINIMUM) {
    result->grade_interpolated = (float) GRADE_NR_MINIMUM;
    return TRUE;
  }

  /* Linearly interpolate decimal portion */
  float decimal = 0.0;

  /* High-end saturation */
  if (i > 0 && i < GRADE_NR_TOTAL) {
    float difference = (
      result->values[i] - result->values[i - 1]
    );
    if (difference != 0.0) {
      decimal = (
        difference > 0 ?
          (y - result->values[i - 1]) / difference
            : (result->values[i] - y) / -difference
      );
    }
  }

  /* Save results */
  result->grade_interpolated = (float) result->grade + decimal;

  /* Success */
  return TRUE;
}

