#ifndef __CPPCODE_H__
#define __CPPCODE_H__

#include <exception>

namespace mynamespace {
  class mycppexcept: public std::exception {
    virtual const char * what () const throw () {
      return "C++ exception happened";
    }
  };

  void myFunc (void) throw (mycppexcept);
}

#endif //__CPPCODE_H__
