#include "main.h"

#define LOG_BUFFER_SIZE 256

void cdiag (LOG_LEVEL level, const char * file,
            unsigned line, const char * fmt, ...)
{
    char * buffer = alloca (LOG_BUFFER_SIZE);
    memset (buffer, 0, LOG_BUFFER_SIZE);

    va_list args;
    va_start (args, fmt);
    vsprintf (buffer, fmt, args);
    va_end (args);
    
    char * buffer_message = alloca (LOG_BUFFER_SIZE);
    memset (buffer_message, 0, LOG_BUFFER_SIZE);
    snprintf (buffer_message, LOG_BUFFER_SIZE, "%s:%i [%s]", file, line, buffer);

    switch (level)
    {
    case INFO:
        pyinfo (buffer_message);
        break;

    case DEBUG:
        pydebug (buffer_message);
        break;

    case ERROR:
        pyerror (buffer_message);
        break;
    }
}

int main (int argc, char ** argv)
{
  /* Boiler plate init Python */
  Py_SetProgramName (argv [0]);
  Py_Initialize ();

  /* Init our config module into Python memory */
  initlogger ();

  if (argc >= 2)
    {
      /* call directly into our cython module parseConfig */
      initLogging (argv [1]);

      info ("info message with string [%s]", argv [0]);
      debug ("debug message with integer [%i]", 7);
      error ("error message with nothing..");
    }
  else
    printf ("require path to output logfile...\n");

  /* cleanup python before exit ... */
  Py_Finalize ();

  return 0;
}
