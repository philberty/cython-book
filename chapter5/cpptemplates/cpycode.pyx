cimport cpycode
from libcpp.string cimport string

cdef LinkedList[string] * list = new LinkedList[string]()
cdef int i
for i in range (5):
    list.append ("whoop %i" % i)
