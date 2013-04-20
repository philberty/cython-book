cdef extern from "data.h":
    struct data:
        int val
    ctypedef data data_t
