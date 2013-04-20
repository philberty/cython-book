#! /usr/bin/env python

import socket

def main ():
    nick = 'myircbot'
    chan = 'mybot'
    irc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    irc.connect (('irc.oftc.net', 6667))
    irc.recv (4096)

    irc.send('NICK ' + nick + '\r\n')
    irc.send('JOIN ' + chan + '\r\n')
    irc.send('PRIVMSG ' + chan + ' :Hello.\r\n') #Send a Message to the  channel

if __name__ == "__main__":
    main ()
