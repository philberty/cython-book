#include <stdio.h>

#include "ccode.h"

int c_main (struct function * f)
{
  printf ("Going to try and exec %s\n", f->name);
  return f->ptr ();
}
