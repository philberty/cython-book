cdef extern from "cppcode.h" namespace "mynamespace":
    cppclass Car:
        Car ()
        void printCar ()
        void setWheels (int)
        void setDoors (int)
