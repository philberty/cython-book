cdef extern from "AddFunction.h":
    cdef int AddFunction(int, int)

def Add(a, b):
    return AddFunction(a, b)
