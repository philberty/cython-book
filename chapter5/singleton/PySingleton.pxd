cdef extern from "Singleton.h" namespace "CythonBook":

    cdef cppclass MySingleton:
        
        @staticmethod
        MySingleton& getInstance()
    
        int getValue()

