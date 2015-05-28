
#ifndef __UTIL_H__
#define __UTIL_H__

/**
 * @name boolean_t:
 */
typedef uint8_t boolean_t;

#ifndef FALSE
  #define FALSE (0)
#endif

#ifndef TRUE
  #define TRUE (!(FALSE))
#endif

#endif /* __UTIL_H__ */

