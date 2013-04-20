#include "main.h"

void cinfo (const char * file, unsigned line,
            const char * fmt, ...)
{
  char buffer [256];
  va_list args;
  va_start (args, fmt);
  vsprintf (buffer, fmt, args);
  va_end (args);

  char buf [512];
  snprintf (buf, sizeof (buf), "%s-%i -> %s",
            file, line, buffer);
  pyinfo (buf);
}

void cdebug (const char * file, unsigned line,
             const char * fmt, ...)
{
  char buffer [256];
  va_list args;
  va_start (args, fmt);
  vsprintf (buffer, fmt, args);
  va_end (args);

  char buf [512];
  snprintf (buf, sizeof (buf), "%s-%i -> %s",
            file, line, buffer);
  pydebug (buf);
}

void cerror (const char * file, unsigned line,
             const char * fmt, ...)
{
  char buffer [256];
  va_list args;
  va_start (args, fmt);
  vsprintf (buffer, fmt, args);
  va_end (args);

  char buf [512];
  snprintf (buf, sizeof (buf), "%s-%i -> %s",
            file, line, buffer);
  pyerror (buf);
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

      info ("info message");
      debug ("debug message");
      error ("error message");
    }
  else
    printf ("require path to output logfile...\n");

  /* cleanup python before exit ... */
  Py_Finalize ();

  return 0;
}
