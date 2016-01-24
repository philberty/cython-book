all:
	cython -2 -o PyMessageServer.c PyMessageServer.pyx
	gcc -g -O2 -Wall -fpic -c AsyncMessageServer.c -o AsyncMessageServer.o `python-config --includes`
	gcc -g -O2 -Wall -fpic -c PyMessageServer.c -o PyMessageServer.o `python-config --includes`
	gcc -g -O2 -shared -o PyMessageServer.so AsyncMessageServer.o PyMessageServer.o -levent `python-config --libs`

clean:
	rm -f *.o *.pyc PyMessageServer.c PyMessageServer.so
