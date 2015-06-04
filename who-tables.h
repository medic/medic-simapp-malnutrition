
#ifndef __WHO_TABLES_H__
#define __WHO_TABLES_H__

#include "polynomial.h"

/**
 * @name who_table_type_t:
 */
typedef enum {
  T_WFA = 1,
  T_LHFA,
  T_WFL
} who_table_type_t;

/**
 * @name who_gender_t:
 */
typedef enum {
  G_FEMALE = 1,
  G_MALE
} who_gender_t;


/**
 * @name who_tables:
 */
#ifdef __AVR__
  extern const PROGMEM polynomial_table_entry_t who_tables[];
#else
  extern const polynomial_table_entry_t who_tables[];
#endif

#endif /* __WHO_TABLES_H__ */

