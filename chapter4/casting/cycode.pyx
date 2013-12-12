cdef class foobar:
    pass

cdef class A:
     pass
cdef class B (A):
     pass

cdef A class1 = A ()
cdef B class2 = B ()
cdef B x = <B?> class1
