from mRoster import Roster
cimport pyserver
import irc

roster = None

class ExampleIrcBot (irc.bot.SingleServerIRCBot):
    def __init__ (self, channel, nickname, server, port=6667):
        irc.bot.SingleServerIRCBot.__init__(self, [(server, port)], nickname, nickname)
        self.channel = channel

    def on_nicknameinuse(self, c, e):
        c.nick(c.get_nickname() + "_")

    def on_welcome(self, c, e):
        c.join(self.channel)

    def on_privmsg(self, c, e):
        self.do_command(e, e.arguments[0])

    def on_pubmsg(self, c, e):
        a = e.arguments[0].split(":", 1)
        if len(a) > 1 and irc.strings.lower(a[0]) == irc.strings.lower(self.connection.get_nickname()):
            self.do_command(e, a[1].strip())
        return

    def on_dccmsg(self, c, e):
        c.privmsg("You said: " + e.arguments[0])

    def on_dccchat(self, c, e):
        if len(e.arguments) != 2:
            return
        args = e.arguments[1].split()
        if len(args) == 4:
            try:
                address = ip_numstr_to_quad(args[2])
                port = int(args[3])
            except ValueError:
                return
            self.dcc_connect(address, port)


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
