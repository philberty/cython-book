#include <iostream>
#include "cppcode.h"

using namespace std;

void mynamespace::myFunc (void) {
  cout << "Inside myFunc!" << endl;
}

void mynamespace::myClass::printMe (void) {
  cout << x << endl;
}
