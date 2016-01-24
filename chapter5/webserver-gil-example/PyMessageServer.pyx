from MessageServerRoster import Roster

cimport PyMessageServer
import threading
import logging

## GLOBALS
_ROSTER = Roster()


cdef int pyconnect_callback(client *c, char * args):
    clientExists = _ROSTER.handle_connect_event(c.cid)
    return 1 if clientExists is True else 0


cdef int pydisconnect_callback(client *c, char * args):
    _ROSTER.handle_disconnect_event(c.cid)
    return 0


cdef int pyread_callback(client *c, char * message):
    _ROSTER.handle_read_event(c.cid, message)
    return 0


class MessageServer(threading.Thread):

    _port = None
    
    def __init__ (self, port):
        threading.Thread.__init__(self)
        # self.daemon = True
        self._port = port

    @property
    def roster(self):
        return _ROSTER

    @property
    def port(self):
        return self._port

    @staticmethod
    def set_callbacks():
        SetConnectCallback(pyconnect_callback)
        SetDisconnectCallback(pydisconnect_callback)
        SetReadCallback(pyread_callback)

    def stop(self):
        with nogil:
            StopServer();

    def run(self):
        logging.info("Starting Message Server on localhost:%i" % self.port)
        MessageServer.set_callbacks()
        cdef int cport = self.port
        with nogil:
            StartServer(cport)
        logging.info("Message Server Finished")
            
