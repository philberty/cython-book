cimport pyserver

def pyinit_server (port):
    setConnect_PyCallback (pyconnect_callback)
    setDisconnect_PyCallback (pydisconnect_callback)
    setRead_PyCallback (pyread_callback)
    init_server (port)                
    print "python init server done..."

cdef void pyconnect_callback (client *c, char * args):
  print c.cid, "is online..."

cdef void pydisconnect_callback (client *c, char * args):
  print c.cid, "went offline..."

cdef void pyread_callback (client *c, char * args):
  print c.cid, "said: ", args
