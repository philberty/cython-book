cdef extern from "cppcode.h" namespace "mynamespace":
    cppclass LinkedList[T]:
        LinkedList ()
        void append (T)
        int getLength ()
        void remove (int)
        void printList ()
