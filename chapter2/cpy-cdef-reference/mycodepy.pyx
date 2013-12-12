cdef extern from "mycode.h":
  struct mystruct:
    char * string
    int integer
    char ** string_array
  void printStruct (mystruct *)

def testStruct ():
    cdef mystruct s
    cdef char *array [2]
    s.string = "Hello World"
    s.integer = 2
    array [0] = "foo"
    array [1] = "bar"
    s.string_array = array
    printStruct (&s)

if __name__ == "__main__":
    testStruct ()
