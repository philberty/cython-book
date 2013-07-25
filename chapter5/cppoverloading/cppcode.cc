#include <iostream>
#include "cppcode.h"

using namespace std;

mynamespace::Car::Car (void) {
  doors = 0;
  wheels = 0;
  cout << "Car constructor" << endl;
}

mynamespace::Car::~Car (void) {
  cout << "Car destructor" << endl;
}

mynamespace::Car * mynamespace::Car::operator+ (Car * c)
{
  cout << "inside operator +" << endl;
  mynamespace::Car * ret = new Car ();

  ret->setWheels (wheels + c->wheels);
  ret->setDoors (doors + c->doors);
  return ret;
}

void mynamespace::Car::printCar (void) {
  cout << "Car has " << doors << " doors"
       << " and " << wheels << " wheels"
       << endl;
}
