cdef extern from "cppcode.h" namespace "mynamespace":
    void myFunc () except +RuntimeError
