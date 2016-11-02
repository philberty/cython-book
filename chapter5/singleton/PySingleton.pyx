cimport PySingleton


# this is now wrapped up for usage within cython code
cdef class CpyMySingleton:

    cdef MySingleton* _thisptr

    def __cinit__(self):
        self._thisptr = &(MySingleton.getInstance())

    @property
    def value(self):
        return self._thisptr.getValue()

    @value.setter
    def value(self, val):
        self._thisptr.setValue(val)

    def doSomething(self, val):
        return self._thisptr.doSomething(val)


# this is a proxy class to allow for usage within full python
class PyMySingleton:

    __instance = CpyMySingleton()

    @staticmethod
    def getInstance():
        return PyMySingleton()

    def __getattr__(self, attr):
        """ Delegate access to implementation """
        return getattr(self.__instance, attr)

    def __setattr__(self, attr, value):
        """ Delegate access to implementation """
        return setattr(self.__instance, attr, value)
                    
