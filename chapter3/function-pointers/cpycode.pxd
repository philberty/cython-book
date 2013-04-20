cdef extern from "ccode.h":
    struct function:
        char * name
        int (*ptr)()
    int c_main (function *)
