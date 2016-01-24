cdef extern from "AsyncMessageServer.h":
    struct client:
        int fd
        char * cid
        void * event

    ctypedef int (*callback_t)(const client *, char *)
  
    void SetConnectCallback(callback_t)
    void SetDisconnectCallback(callback_t)
    void SetReadCallback(callback_t)
  
    void StartServer(int) nogil
    void StopServer() nogil

