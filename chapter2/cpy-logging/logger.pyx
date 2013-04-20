import logging

cdef public void initLogging (char * logfile):
    logging.basicConfig (filename = logfile,
                         level = logging.DEBUG,
                         format = '%(levelname)s %(asctime)s: %(message)s',
                         datefmt = '%m/%d/%Y %I:%M:%S')

cdef public void pyinfo (char * message):
    logging.info (message)

cdef public void pydebug (char * message):
    logging.debug (message)

cdef public void pyerror (char * message):
    logging.error (message)
