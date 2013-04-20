cdef extern from "mycode.h":
    cdef int myfunc (int, int)

def callCfunc ():
    print myfunc (1,2)
