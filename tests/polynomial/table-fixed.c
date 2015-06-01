
#include <assert.h>
#include "polynomial.h"

int main(int argc, char *argv[]) {

  /* Simple */
  polynomial_table_entry_t t1[] = {
    { { 1, 1, 0, 0 }, { { 0, 10 }, { 0, 1, 1, 1, 1, 1, 1 } } },
    { { 1, 1, 1, 0 }, { { 11, 20 }, { 0, 2, 2, 2, 2, 2, 2 } } },
    { { 1, 1, 2, 0 }, { { 21, 30 }, { 0, 3, 3, 3, 3, 3, 3 } } },
    POLYNOMIAL_TABLE_END
  };

  polynomial_table_id_t id1[] = { 1, 1, 1 };
  assert(!polynomial_table_entry_match(&t1[0], 3, id1, NULL));
  assert(polynomial_table_entry_match(&t1[1], 3, id1, NULL));
  assert(!polynomial_table_entry_match(&t1[2], 3, id1, NULL));
  assert(polynomial_table_find(t1, 3, id1, NULL) == &t1[1]);
  assert(polynomial_table_find(&t1[2], 3, id1, NULL) == NULL);

  /* Larger identifier set */
  polynomial_table_entry_t t2[] = {
    { { 1, 1, 0, 0 }, { { 0, 10 }, { 0, 1, 1, 1, 1, 1, 1 } } },
    { { 1, 1, 1, 2 }, { { 11, 20 }, { 0, 2, 2, 2, 2, 2, 2 } } },
    { { 1, 1, 2, 4 }, { { 21, 30 }, { 0, 3, 3, 3, 3, 3, 3 } } },
    POLYNOMIAL_TABLE_END
  };

  polynomial_table_id_t id2a[] = { 1, 1, 1 };
  assert(!polynomial_table_entry_match(&t2[0], 3, id2a, NULL));
  assert(polynomial_table_entry_match(&t2[1], 3, id2a, NULL));
  assert(!polynomial_table_entry_match(&t2[2], 3, id2a, NULL));
  assert(polynomial_table_find(t2, 3, id2a, NULL) == &t2[1]);

  polynomial_table_id_t id2b[] = { 1, 1 };
  assert(polynomial_table_entry_match(&t2[0], 2, id2b, NULL));
  assert(polynomial_table_entry_match(&t2[1], 2, id2b, NULL));
  assert(polynomial_table_entry_match(&t2[2], 2, id2b, NULL));
  assert(polynomial_table_find(t2, 2, id2b, NULL) == t2);

  polynomial_table_id_t id2c[] = { 1, 1, 0, 0, 1 };
  assert(!polynomial_table_entry_match(&t2[0], 5, id2c, NULL));
  assert(!polynomial_table_entry_match(&t2[1], 5, id2c, NULL));
  assert(!polynomial_table_entry_match(&t2[2], 5, id2c, NULL));
  assert(polynomial_table_find(t2, 5, id2c, NULL) == NULL);

  return 0;
}

