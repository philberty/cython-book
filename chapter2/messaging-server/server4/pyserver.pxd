cdef extern from "server.h":
  struct client:
    int fd
    void * event
    char * cid
  ctypedef int (*callback)(client *, char *)
  void setConnect_PyCallback (callback)
  void setDisconnect_PyCallback (callback)
  void setRead_PyCallback (callback)
  void init_server (int)
