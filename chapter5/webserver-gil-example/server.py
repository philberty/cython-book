#!/usr/bin/env python

from ConfigParser import SafeConfigParser
from PyMessageServer import MessageServer
from WebServer import Dashboard

import optparse
import logging
import sys


def configure_logging():
    root = logging.getLogger()
    root.setLevel(logging.DEBUG)

    ch = logging.StreamHandler(sys.stdout)
    ch.setLevel(logging.DEBUG)
    formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
    ch.setFormatter(formatter)
    root.addHandler(ch)


def main():
    # setup logging
    configure_logging()

    # parse command line
    parser = optparse.OptionParser()
    parser.add_option("--config", dest="config", default=None,
                      help="Path to configuration file")
    options, args = parser.parse_args()
    conf = options.config
    if conf is None:
        sys.exit("No configuration specified")
    
    parser = SafeConfigParser()
    parser.read(conf)

    logging.info("Parsing configuration")
    message_server_port = int(parser.get("MessageServer", "port"))
    web_dashboard_port = int(parser.get("MessageServer", "webport"))
    
    logging.info("trying to start server...")
    message_server = MessageServer(message_server_port)
    message_server.start()

    logging.info("Tying to start web dashboard...")
    dashboard = Dashboard(web_dashboard_port, message_server.roster)
    dashboard.start()

    logging.info("Sopping message server..")
    message_server.stop()

    logging.info("Done..")
    

if __name__ == "__main__":
    main()
