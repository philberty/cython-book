cdef public:
    ctypedef void (*callback)(int)


cdef callback GlobalCallback


cdef public void SetCallback(callback cb):
    global GlobalCallback
    GlobalCallback = cb
    

cdef public void Notify(int value):
    global GlobalCallback
    if GlobalCallback != <callback>0:
        GlobalCallback(value)
