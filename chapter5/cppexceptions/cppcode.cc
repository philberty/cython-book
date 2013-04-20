#include <iostream>
#include "cppcode.h"

using namespace std;

void mynamespace::myFunc (void) throw (mynamespace::mycppexcept){
  mynamespace::mycppexcept ex;
  cout << "About to throw an exception!" << endl;
  throw ex;
}
