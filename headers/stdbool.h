/*                          stdbool.h for the faoss project

Allows booleans in programs as a type

*/
#ifndef __STDBOOL_H_
 #define __STDBOOL_H_


 #ifndef __cplusplus_
  #define bool _Bool
  #define true 1
  #define false 0
  #elif defined(__GNUC__) && !defined(__STRICT_ANSI__)

  #define _Bool bool
  #if __cplusplus_ < 201103L

  #define bool  bool
  #define false false
  #define true  true
  #endif
 #endif //not __cplusplus_

 #define __bool_true_false_are_defined 1

#endif //not __STDBOOL_H_
