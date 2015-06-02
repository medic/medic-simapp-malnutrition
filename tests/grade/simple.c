
#include <assert.h>

#include "grade.h"
#include "who-tables.h"

int main(int argc, char *argv[]) {

  boolean_t valid;
  grade_result_t result;
  polynomial_table_id_t id[] = { T_WFA, G_FEMALE, 0 };

  valid = grade_calculate(&result, who_tables, 3, id, 4, 3.5);
  assert(valid == TRUE);
  assert(result.between[0] == 4);
  assert(result.between[1] == 5);
  assert(result.grade == 0);

  valid = grade_calculate(&result, who_tables, 3, id, 4, 4.0);
  assert(valid == TRUE);
  assert(result.between[0] == 5);
  assert(result.between[1] == 6);
  assert(result.grade == 1);

  return 0;
}

