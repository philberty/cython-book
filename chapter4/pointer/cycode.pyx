cdef void test (int len, int * array):
    cdef int i
    cdef int * ptr = array
    for i in range (len):
        print ptr [0]
        ptr = ptr + 1

def myfunc ():
    cdef int len = 10
    cdef int array [10]
    cdef int i
    for i in range (len):
        array [i] = i + 1
    test (len, array)
