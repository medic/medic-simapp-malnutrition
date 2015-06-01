
#include <assert.h>
#include "polynomial.h"
#include "who-tables.h"

int main(int argc, char *argv[]) {

  polynomial_range_point_t n;
  const polynomial_table_entry_t *e;
  polynomial_result_t result, expect;

  polynomial_table_id_t id[] = { T_WFA, G_FEMALE, -4 };
  assert(polynomial_table_find(who_tables, 0, id, NULL) == NULL);
  assert(polynomial_table_find(who_tables, 1, id, NULL) != NULL);
  assert(polynomial_table_find(who_tables, 2, id, NULL) != NULL);
  assert(polynomial_table_find(who_tables, 3, id, NULL) != NULL);

  n = -1;
  assert(polynomial_table_find(who_tables, 3, id, &n) == NULL);
  n = 0;
  assert(polynomial_table_find(who_tables, 3, id, &n) != NULL);
  n = 1856;
  assert(polynomial_table_find(who_tables, 3, id, &n) != NULL);
  n = 1857;
  assert(polynomial_table_find(who_tables, 3, id, &n) == NULL);

  n = 0;
  e = polynomial_table_find(who_tables, 3, id, &n);
  assert(e != NULL);
  polynomial_evaluate(&result, &e->fn, n);
  expect = 1.675974;
  /* assert(result == expect); */

  n = 1;
  e = polynomial_table_find(who_tables, 3, id, &n);
  assert(e != NULL);
  polynomial_evaluate(&result, &e->fn, n);
  expect = 1.699189;
  /* assert(result == expect); */

  n = 1800;
  e = polynomial_table_find(who_tables, 3, id, &n);
  assert(e != NULL);
  polynomial_evaluate(&result, &e->fn, n);
  expect = 10.304532;
  /* assert(result == expect); */

  return 0;
}

