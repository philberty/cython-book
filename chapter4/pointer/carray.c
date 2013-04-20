#include <stdio.h>

static void test (int, int *);

static
void test (int len, int * array)
{
  int * ptr = array;
  int i;
  for (i = 0; i < len; ++i)
    printf ("%i\n", *ptr++);
}

int main (int argc, char ** argv)
{
  int len = 10;
  int buf[len];

  int i;
  for (i = 0; i < len; ++i)
    buf [i] = i + 1;

  test (len, buf);

  return 0;
}
