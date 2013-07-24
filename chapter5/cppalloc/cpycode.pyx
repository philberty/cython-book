cimport cpycode

cdef Car * c = new Car ()
c.setWheels (4)
c.setDoors (3)
c.printCar ()
del c
