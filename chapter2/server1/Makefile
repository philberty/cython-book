server.o: server.c
	gcc -g -O2 -c server.c -o server.o

pyserver.o: server.o pyserver.pyx
	cython -2 -o pyserver.c pyserver.pyx
	gcc -g -O2 -c pyserver.c -o pyserver.o `python-config --cflags`

all: pyserver.o
	gcc -g -O2 -o mrserver server.o pyserver.o -levent `python-config --libs`

clean:
	rm -f *.o *~ mrserver
