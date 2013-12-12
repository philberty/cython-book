#ifndef __MAIN_H__
#define __MAIN_H__

#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define printflike \
  __attribute__ ((format (printf, 4, 5)))

typedef enum {
    INFO,
    DEBUG,
    ERROR
} LOG_LEVEL ;

extern void printflike cdaig (LOG_LEVEL, const char *, unsigned, const char *, ...);

#define info(...)                                       \
    cdiag (INFO, __FILE__, __LINE__, __VA_ARGS__)
#define error(...)                                      \
    cdiag (ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define debug(...)                                      \
    cdiag (DEBUG, __FILE__, __LINE__, __VA_ARGS__)

#include "logger.h"

#endif //__MAIN_H__
