
#include <assert.h>

#include "grade.h"
#include "who-tables.h"

int main(int argc, char *argv[]) {

  boolean_t valid;
  grade_result_t result;
  polynomial_table_id_t id1[] = { T_WFA, G_FEMALE, 0 };

  valid = grade_calculate(&result, who_tables, 3, id1, -1, 0.0);
  assert(valid == FALSE);

  valid = grade_calculate(&result, who_tables, 3, id1, 2000, 0.0);
  assert(valid == FALSE);

  valid = grade_calculate(&result, who_tables, 3, id1, 4, 1.5);
  assert(valid == TRUE);
  assert(result.between[0] == 0);
  assert(result.between[1] == 0);
  assert(result.grade == -5);

  valid = grade_calculate(&result, who_tables, 3, id1, 4, 1.8);
  assert(valid == TRUE);
  assert(result.between[0] == 0);
  assert(result.between[1] == 1);
  assert(result.grade == -4);

  valid = grade_calculate(&result, who_tables, 3, id1, 4, 3.5);
  assert(valid == TRUE);
  assert(result.between[0] == 4);
  assert(result.between[1] == 5);
  assert(result.grade == 0);

  valid = grade_calculate(&result, who_tables, 3, id1, 4, 4.0);
  assert(valid == TRUE);
  assert(result.between[0] == 5);
  assert(result.between[1] == 6);
  assert(result.grade == 1);

  valid = grade_calculate(&result, who_tables, 3, id1, 4, 6.0);
  assert(valid == TRUE);
  assert(result.between[0] == 8);
  assert(result.between[1] == 9);
  assert(result.grade == 4);

  valid = grade_calculate(&result, who_tables, 3, id1, 10, 6.0);
  assert(valid == TRUE);
  assert(result.between[0] == 7);
  assert(result.between[1] == 8);
  assert(result.grade == 3);

  valid = grade_calculate(&result, who_tables, 3, id1, 10, 6.0);
  assert(valid == TRUE);
  assert(result.between[0] == 7);
  assert(result.between[1] == 8);
  assert(result.grade == 3);

  polynomial_table_id_t id2[] = { T_LHFA, G_MALE, 0 };

  valid = grade_calculate(&result, who_tables, 3, id1, -1, 0.0);
  assert(valid == FALSE);

  valid = grade_calculate(&result, who_tables, 3, id1, 2000, 0.0);
  assert(valid == FALSE);

  valid = grade_calculate(&result, who_tables, 3, id2, 1850, 105.5);
  assert(valid == TRUE);
  assert(result.between[0] == 3);
  assert(result.between[1] == 4);
  assert(result.grade == -1);

  valid = grade_calculate(&result, who_tables, 3, id2, 0, 57.0);
  assert(valid == TRUE);
  assert(result.between[0] == 6);
  assert(result.between[1] == 7);
  assert(result.grade == 2);

  return 0;
}

