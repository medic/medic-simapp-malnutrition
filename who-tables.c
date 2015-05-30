
#include "who-tables.h"

/**
 * @name tables:
 */
static const polynomial_table_entry_t tables[] = {

  { { T_WFA, G_FEMALE, -4 },
    { { 0, 1856 }, {
      1.6759740922389,
      0.0232748769615228
      -0.0000605260015320574,
      0.0000000953741098397645
      -0.0000000000786128884004803,
      0.0000000000000320554496154721,
      -0.000000000000000005111300107195 } } },

  POLYNOMIAL_TABLE_END
};

/**
 * @name who_tables:
 */
const polynomial_table_entry_t *who_tables = tables;

