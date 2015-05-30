
#include <assert.h>
#include "polynomial.h"

int main(int argc, char *argv[]) {

  boolean_t valid;
  polynomial_result_t result;

  /* Simple */
  polynomial_table_entry_t t[] = {
    { 3, { 1, 1, 0 }, { 6, { 0, 10 }, { 0, 1, 1, 1, 1, 1, 1 } } },
    { 3, { 1, 1, 0 }, { 6, { 11, 20 }, { 0, 2, 2, 2, 2, 2, 2 } } },
    { 3, { 1, 1, 0 }, { 6, { 21, 30 }, { 0, 3, 3, 3, 3, 3, 3 } } },
    POLYNOMIAL_TABLE_END
  };

  return 0;
}

