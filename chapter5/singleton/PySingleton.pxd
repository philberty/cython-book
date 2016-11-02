cdef extern from "Singleton.h":

    cdef cppclass MySingleton:
        
        @staticmethod
        MySingleton& getInstance()
    
        int getValue()
        
        void setValue(int val)

        int doSomething(int val)

