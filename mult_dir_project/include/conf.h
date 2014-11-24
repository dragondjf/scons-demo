#ifndef CONF_H_
#define CONF_H_

#ifdef SHARE_LIB	/* { */
#define D_API __declspec(dllexport)
#else						/* }{ */
#define D_API __declspec(dllimport)
#endif

#endif