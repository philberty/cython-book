from libcpp.map cimport map

cdef map[int,int] mymap
cdef int i
for i in range (10):
    mymap[i] = (i + 1)

for i in range (10):
    print mymap[i]
