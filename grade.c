
#include "grade.h"

/**
 * @name grade_calculate:
 */
boolean_t grade_calculate(grade_result_t *result,
                          const polynomial_table_entry_t *t,
                          uint8_t nr_identifiers,
                          polynomial_table_id_t *id,
                          polynomial_range_point_t x,
                          polynomial_result_t input) {

  unsigned int i = 0;
  int8_t grade = GRADE_NR_MINIMUM;
  const polynomial_table_entry_t *e = t;

  if (nr_identifiers <= 0) {
    return FALSE;
  }

  /* Clear target */
  memset(result, '\0', sizeof(*result));

  /* Evaluate each curve */
  while (grade <= GRADE_NR_MAXIMUM) {

    id[nr_identifiers - 1] = grade;
    e = polynomial_table_find(e, nr_identifiers, id, &x);

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
    if (result->values[i] >= input) {
      break;
    }
  }

  /* Yield results */
  result->between[1] = i;
  result->between[0] = (i > 0 ? i - 1 : i);
  result->grade = (GRADE_NR_MINIMUM - 1) + i;

  return TRUE;
}

