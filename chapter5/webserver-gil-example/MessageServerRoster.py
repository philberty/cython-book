import logging

class Roster:

    _clients = { }

    def handle_connect_event(self, client):
        """
        :returns True if client already exists else false
        """
        logging.info("connect: %s" % client)
        if client in self._clients:
            return True
        self._clients[client] = None
        return False;

    def handle_disconnect_event(self, client):
        logging.info("disconnect: %s" % client)
        self._clients.pop(client, None)

    def handle_read_event(self, client, message):
        logging.info("read: %s:[%s]" % (client, message))
        self._clients[client] = message

    def client_list(self):
        return self._clients
