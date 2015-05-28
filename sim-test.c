
#include <turbo/turbo.h>
#include <string.h>
#include "datetime.h"

/**
 * @name lc_app_name:
 */
const char PROGMEM lc_app_name[] = "Display Date/Time";

/**
 * @name display_datetime:
 */
void display_datetime(void *data) {

  stk_datetime_t t;

  if (!stk_retrieve_current_time(&t, NULL)) {
    display_text("Error retrieving time", NULL);
    return;
  }

  uint8_t rv[128];
  uint8_t *r = rv;

  memset(&rv, '\0', 128);

  r = sprinti(r, t.month);
  *r = '/'; r++;
  r = sprinti(r, t.day);
  *r = '/'; r++;
  r = sprinti(r, t.year);
  *r = ' '; r++;

  r = sprinti(r, t.hour);
  *r = ':'; r++;
  r = sprinti(r, t.minute);

  display_text(rv, "Result");
}

/**
 * @name turbo_handler:
 */
void turbo_handler(u8 action, void *data)
{
  switch (action)
  {
    case ACTION_APP_REGISTER: {
      set_proc_8(PROC_8_CONFIG_SETUP, 0);
      set_proc_8(PROC_8_LANGUAGE, LC_ENGLISH);
    }
    case ACTION_INSERT_MENU: {
      insert_menu(lc_app_name);
      break;
    }
    case ACTION_MENU_SELECTION: {
      stk_thread((void *) display_datetime, data);
      break;
    }
    default: {
      break;
    }
  }
}

