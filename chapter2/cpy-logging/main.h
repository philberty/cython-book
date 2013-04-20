#ifndef __MAIN_H__
#define __MAIN_H__

#include <Python.h>

#include <stdio.h>
#include <stdarg.h>

#define printflike \
  __attribute__ ((format (printf, 3, 4)))

extern void printflike cinfo (const char *, unsigned, const char *, ...);
extern void printflike cdebug (const char *, unsigned, const char *, ...);
extern void printflike cerror (const char *, unsigned, const char *, ...);

#define info(...)                               \
  cinfo (__FILE__, __LINE__, __VA_ARGS__)

#define error(...)                              \
  cerror (__FILE__, __LINE__, __VA_ARGS__)

#define debug(...)                              \
  cdebug (__FILE__, __LINE__, __VA_ARGS__)

#include "logger.h"

#endif //__MAIN_H__
