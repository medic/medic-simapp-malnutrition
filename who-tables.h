
#ifndef __WHO_TABLES_H__
#define __WHO_TABLES_H__

#include "polynomial.h"

/**
 * @name who_table_type_t:
 */
typedef enum {
  T_START = 0,
  T_WFA,
  T_LHFA,
  T_WFH,
  T_END
} who_table_type_t;

/**
 * @name who_nr_table_types:
 */
#define WHO_NR_TABLE_TYPES (T_END - 1)

/**
 * @name who_gender_t:
 */
typedef enum {
  G_START = 0,
  G_FEMALE,
  G_MALE,
  G_END
} who_gender_t;

/**
 * @name who_nr_genders:
 */
#define WHO_NR_GENDERS (G_END - 1)

/**
 * @name who_tables:
 */
#ifdef __AVR__
  extern const PROGMEM polynomial_table_entry_t who_tables[];
#else
  extern const polynomial_table_entry_t who_tables[];
#endif

#endif /* __WHO_TABLES_H__ */

