from twisted.web import server, resource
from twisted.internet import reactor

DATA = None

class Simple (resource.Resource):
    isLeaf = True
    def render_GET (self, request):
        global DATA
        resp = "<html>Messaging Server Stats<ol>"
        for i in DATA.getClients ():
            resp += ("<li>" + i + "</li>")
        resp += "</ol></html>"
        return resp

def WebServer (port, roster):
    global DATA
    DATA = roster
    site = server.Site (Simple())
    reactor.listenTCP (port, site)
    reactor.run ()
