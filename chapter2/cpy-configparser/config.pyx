from ConfigParser import SafeConfigParser, NoSectionError

cdef extern from "main.h":
    struct config:
        char * path
        int number

# declaring struct on the stack so no need for memory alloc
cdef config myconfig

cdef public config * parseConfig (char * cfg):
    # initilize the global stack variable for our config...
    myconfig.path = NULL
    myconfig.number = 0
    # buffers for assigning python types into C types
    cdef char * path = NULL
    cdef number = 0
    parser = SafeConfigParser ()
    try:
        parser.readfp (open (cfg))
        pynumber = int (parser.get ("example", "number"))
        pypath = parser.get ("example", "path")
    except NoSectionError:
        print "No section named example"
        return NULL
    except IOError:
        print "no such file ", cfg
        return NULL
    finally:
        myconfig.number = pynumber
        myconfig.path = pypath
    return &myconfig
