#ifndef __MYCODE_H__
#define __MYCODE_H__

struct mystruct {
  char * string;
  int integer;
  char ** string_array;
};

extern void printStruct (/*const*/ struct mystruct *);

#endif //__MYCODE_H__
