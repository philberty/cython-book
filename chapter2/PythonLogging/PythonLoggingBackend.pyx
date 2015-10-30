import logging

cdef public void initLoggingWithLogFile(const char * logfile):
    logging.basicConfig(filename = logfile,
                        level = logging.DEBUG,
                        format = '%(levelname)s %(asctime)s: %(message)s',
                        datefmt = '%m/%d/%Y %I:%M:%S')

cdef public void python_info(char * message):
    logging.info(message)

cdef public void python_debug(char * message):
    logging.debug(message)

cdef public void python_error(char * message):
    logging.error(message)
