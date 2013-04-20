from messagingEngine import Roster

cimport pyserver

roster = None

def pyinit_server (port):
    global roster
    roster = Roster ()
    setConnect_PyCallback (pyconnect_callback)
    setDisconnect_PyCallback (pydisconnect_callback)
    setRead_PyCallback (pyread_callback)
    init_server (port)                
    print "python init server done..."

cdef int pyconnect_callback (client *c, char * args):
  print "client tried to connect..."
  if roster.handleEvent (args): return 1
  else: return 0

cdef int pydisconnect_callback (client *c, char * args):
  print "client disconnected..."
  if roster.handleEvent (c.cid, data=True): return 1
  else: return 0

cdef int pyread_callback (client *c, char * args):
  print "client said something"
  if roster.handleEvent (c.cid, data=args, rosterEvent=False): return 1
  else: return 0
