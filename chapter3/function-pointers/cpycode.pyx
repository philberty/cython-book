cimport cpycode

cdef int callee ():
    print "Hello World!"
    return 0

cdef void pymain ():
    cdef char * name = "callee"
    cdef function fbase
    fbase.name = name
    fbase.ptr = callee
    print c_main (&fbase)

if __name__ == "__main__":
    pymain ()
