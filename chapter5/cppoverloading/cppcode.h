#ifndef __CPPCODE_H__
#define __CPPCODE_H__

namespace mynamespace {
  class Car {
    int doors;
    int wheels;
  public:
    Car ();
    ~Car ();
    Car * operator+(Car *);
    void printCar (void);
    void setWheels (int x) { wheels = x; };
    void setDoors (int x) { doors = x; };
  };
};

#endif //__CPPCODE_H__
