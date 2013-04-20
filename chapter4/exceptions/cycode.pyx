cdef void somethingElse ():
    print "Away doing something else now..."

cdef public int myfunc () except *:
    cdef int retval = -1
    # do stuff...
    return retval

cdef public void run ():
    try:
        myfunc ()
        somethingElse ()
    except Exception:
        print "Something wrong"
