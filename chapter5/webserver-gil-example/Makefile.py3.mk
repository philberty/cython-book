LIBEVENT_INC=/usr/local/include
LIBEVENT_LIB=/usr/local/lib

all:
	cython -3 -o PyMessageServer.c PyMessageServer.pyx
	gcc -g -O2 -Wall -fpic -c AsyncMessageServer.c -o AsyncMessageServer.o -I$(LIBEVENT_INC) `python3-config --includes`
	gcc -g -O2 -Wall -fpic -c PyMessageServer.c -o PyMessageServer.o `python3-config --includes`
	gcc -g -O2 -shared -o PyMessageServer.so AsyncMessageServer.o PyMessageServer.o -levent -L$(LIBEVENT_LIB) `python3-config --ldflags --libs`

clean:
	rm -f *.o *.pyc PyMessageServer.c PyMessageServer.so
