#ifndef __CCODE_H__
#define __CCODE_H__

struct function {
  char * name;
  int (*ptr)(void);
};

extern int c_main (struct function *);

#endif //__CCODE_H__
