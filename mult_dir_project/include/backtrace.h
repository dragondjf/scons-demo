/**
 * @file   backtrace.h
 * @author Late Lee <http://www.latelee.org>
 * @date   Thu Apr  7 2011
 * 
 * @brief  none
 * 
 * 
 */

#ifndef _BACKTRACE_H
#define _BACKTRACE_H

#include "conf.h"
/* Even complicated programs rather seldom have a nesting 
 * level of more than, say, 50 and with 200 possible entries
 * probably all programs should be covered. -- from glibc manual
 */
/* here, we let it be 30 */
#define NEST	30

#ifdef __cplusplus
extern "C" {
#endif

D_API void print_trace(int sig);
D_API void print_trace_fd(int sig);
D_API void print_trace_file(int sig);

#ifdef __cplusplus
}
#endif

#endif /* _BACKTRACE_H */