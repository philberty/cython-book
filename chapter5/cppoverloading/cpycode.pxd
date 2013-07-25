cdef extern from "cppcode.h" namespace "mynamespace":
    cppclass Car:
        Car ()
        Car * operator+ (Car *)
        void printCar ()
        void setWheels (int)
        void setDoors (int)
