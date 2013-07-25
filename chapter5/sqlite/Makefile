all:
	cython -2 -o pyserver.c pyserver.pyx
	gcc -g -O2 -Wall -fpic -c server.c -o server.o `python-config --includes`
	gcc -g -O2 -Wall -fpic -c pyserver.c -o pyserver.o `python-config --includes`
	gcc -g -O2 -shared -o pyserver.so server.o pyserver.o -levent `python-config --libs`

clean:
	rm -f *.o *~ pyserver.c pyserver.so
