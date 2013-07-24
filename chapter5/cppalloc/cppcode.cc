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

void mynamespace::Car::printCar (void) {
  cout << "Car has " << doors << " doors"
       << " and " << wheels << " wheels"
       << endl;
}
