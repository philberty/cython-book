#include <Python.h>
#include <stdio.h>
#include <stdarg.h>

#include "PythonLoggingBackend.h"
#include "NativeLogging.h"

void native_logging_info(const char * file, unsigned line, const char * fmt, ...)
{
    char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    va_end(args);

    char buf[512];
    snprintf(buf, sizeof(buf), "%s:%i -> %s", file, line, buffer);
    python_info(buf);
}

void native_logging_debug(const char * file, unsigned line,const char * fmt, ...)
{
    char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    va_end(args);

    char buf[512];
    snprintf(buf, sizeof(buf), "%s-%i -> %s", file, line, buffer);
    python_debug(buf);
}

void native_logging_error(const char * file, unsigned line, const char * fmt, ...)
{
    char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    va_end(args);

    char buf[512];
    snprintf(buf, sizeof(buf), "%s:%i -> %s", file, line, buffer);
    python_error(buf);
}

void SetupNativeLogging(const char * logFileName)
{
    /* Boiler plate init Python */
    Py_Initialize();

    /* Init our config module into Python memory */
    initPythonLoggingBackend();

    /* call directly into our cython module parseConfig */
    initLoggingWithLogFile(logFileName);
}

void CloseNativeLogging()
{
    /* cleanup python before exit ... */
    Py_Finalize();
}
