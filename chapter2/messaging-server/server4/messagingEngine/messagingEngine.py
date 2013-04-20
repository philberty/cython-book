class Client:
    def __init__ (self, cid):
        self._cid = cid

    @property
    def clientID (self):
        return self._cid

    def handleMessage (self, data):
        print self.clientID, " :: ", data

class Roster:
    def __init__ (self):
        self._roster = { }

    def isOnline (self, client):
        if client in self._roster: return True
        else: return False

    def handleEvent (self, client, data=None, rosterEvent=True):
        if rosterEvent:
            # basic mechanism to say client is going offline if its a rosterEvent
            if data:
                print "Client is going offline ", client
                self._roster[client] = None
                return True
            else:
                if not self.isOnline (client):
                    print "New client instance ", client
                    self._roster[client] = Client (client)
                else:
                    print "Client already online from this address ", client
                    return True
        else: self._roster[client].handleMessage (data)
        return False
