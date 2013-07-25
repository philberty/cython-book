cimport pyserver
from mRoster import Roster
import sqlite3

sqlconn = None
roster = None

def pyinit_server (port):
    global roster, sqlconn
    sqlconn = sqlite3.connect ('sqlite.db')
    roster = Roster ()
    # Setting callbacks
    setConnect_PyCallback (pyconnect_callback)
    setDisconnect_PyCallback (pydisconnect_callback)
    setRead_PyCallback (pyread_callback)
    # start libvent server
    init_server (port)
    print "Done...!"

cdef int pyconnect_callback (client *c, char * args):
    global sqlconn
    sqlconn.
    print "client tried to connect..."
    if roster.handleEvent (args): return 1
    else: return 0

cdef int pydisconnect_callback (client *c, char * args):
    global sqlconn
    print "client disconnected..."
    if roster.handleEvent (c.cid, data=True): return 1
    else: return 0

cdef int pyread_callback (client *c, char * args):
    global sqlconn
    print "client said something"
    if roster.handleEvent (c.cid, data=args, rosterEvent=False): return 1
    else: return 0
