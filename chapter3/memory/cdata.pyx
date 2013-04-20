cimport cdata
from libc.stdlib cimport malloc, free

cdef class Data:
    cdef cdata.data_t * _c_data

    def __cinit__ (self, val):
        self._c_data = <data_t *> malloc (sizeof (data_t))
        if not self._c_data: raise MemoryError ()
        self._c_data.val = val
    
    cdef int getVal (self):
        if self._c_data: return self._c_data.val
        else: return -1
    
    def __dealloc__ (self):
        if self._c_data is not NULL:
            free (self._c_data)
            self._c_data = NULL

    def __str__ (self):
        if self._c_data is not NULL:
            return "%s" % self.getVal ()
        else:
            return "Object not initilized!"
