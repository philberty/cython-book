#include <Python.h>
#include "cycode.h"

int main (int argc, char ** argv)
{
  Py_Initialize ();

  initcycode ();
  run ();

  Py_Finalize ();

  return 0;
}
