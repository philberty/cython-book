cdef extern from "Data.h":
    struct data:
        int value
    ctypedef data data_t
