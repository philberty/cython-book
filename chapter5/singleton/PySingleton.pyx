cimport PySingleton


# this is now wrapped up for usage within cython code
cdef class CpyMySingleton:

    cdef MySingleton* _thisptr

    def __cinit__(self):
        self._thisptr = &(MySingleton.getInstance())

    def getValue(self):
        return self._thisptr.getValue()


# this is a proxy class to allow for usage within full python
class PyMySingleton:
    
    def __init__(self):
        self._wrapped = CpyMySingleton()
        
    def getValue(self):
        return self._wrapped.getValue()
