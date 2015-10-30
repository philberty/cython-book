#include <Python.h>

int main (int argc, char ** argv)
{
  /* Boiler plate init Python */
  Py_SetProgramName (argv [0]);
  Py_Initialize ();

  /* Init our config module into Python memory */
  initpublicTest ();
  cythonFunction ();

  /* cleanup python before exit ... */
  Py_Finalize ();

  return 0;
}
