/**
 * @file   foo.h
 * @author Late Lee <http://www.latelee.org>
 * @date   Thu Apr  7 2011
 * 
 * @brief  none
 * 
 * 
 */

#ifndef FOO_H_
#define FOO_H_

#include <conf.h>

#ifdef __cplusplus
extern "C" {
#endif

D_API void foo(int i);
D_API int hello_foo(void);

#ifdef __cplusplus
}
#endif

#endif
