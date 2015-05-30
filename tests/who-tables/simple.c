
#include <assert.h>
#include "polynomial.h"
#include "who-tables.h"

int main(int argc, char *argv[]) {

  polynomial_table_id_t id[] = { T_WFA, G_FEMALE, -4 };
  assert(polynomial_table_find(who_tables, 0, id) == NULL);
  assert(polynomial_table_find(who_tables, 1, id) != NULL);
  assert(polynomial_table_find(who_tables, 2, id) != NULL);
  assert(polynomial_table_find(who_tables, 3, id) != NULL);

  return 0;
}

