cimport pyserver
import threading
import webserver
from mRoster import Roster

roster = None

class RunCServer (threading.Thread):
    def __init__ (self, port):
        self.port = port
        threading.Thread.__init__ (self)

    def run (self):
        cdef int cport = self.port
        with nogil:
            init_server (cport)

def pyinit_server (port, webport):
    global roster
    roster = Roster ()
    # Setting callbacks
    setConnect_PyCallback (pyconnect_callback)
    setDisconnect_PyCallback (pydisconnect_callback)
    setRead_PyCallback (pyread_callback)
    # start libvent server
    cs = RunCServer (port)
    cs.start ()
    # start webserver
    webserver.WebServer (webport, roster)
    cs.join ()

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
