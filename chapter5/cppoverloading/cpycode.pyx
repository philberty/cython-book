cimport cpycode

cdef Car * c = new Car ()
cdef Car * cc = new Car ()

c.setWheels (4)
c.setDoors (3)
c.printCar ()

cc.setWheels (8)
cc.setDoors (6)
cc.printCar ()

cdef Car *ccc = c[0] + cc
ccc.printCar ()

del c, cc, ccc
