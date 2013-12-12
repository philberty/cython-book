#include "main.h"

static void printConfig (const struct config * cfg)
{
  printf ("cfg->path = %s\n", cfg->path);
  printf ("cfg-number = %i\n", cfg->number);
}

int main (int argc, char ** argv)
{
  /* Boiler plate init Python */
  Py_SetProgramName (argv [0]);
  Py_Initialize ();

  /* Init our config module into Python memory */
  initconfig ();

  if (argc >= 2)
    {
      /* call directly into our cython module parseConfig */
      struct config * cfg = parseConfig (argv [1]);
      printConfig (cfg);        
    }
  else
    printf ("require path to config...\n");

  /* cleanup python before exit ... */
  Py_Finalize ();

  return 0;
}
