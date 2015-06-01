
#include <assert.h>
#include "polynomial.h"
#include "who-tables.h"

int main(int argc, char *argv[]) {

  polynomial_range_point_t n;
  polynomial_result_t result;
  const polynomial_table_entry_t *e;

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
  assert(result == 1.6759741306304931640625);

  n = 1;
  e = polynomial_table_find(who_tables, 3, id, &n);
  assert(e != NULL);
  polynomial_evaluate(&result, &e->fn, n);
  assert(result == 1.69918859004974365234375);

  n = 1800;
  e = polynomial_table_find(who_tables, 3, id, &n);
  assert(e != NULL);
  polynomial_evaluate(&result, &e->fn, n);
  /* assert(result == 10.30453205108642578125); */

  return 0;
}

