all:
	cython cdata.pyx
	gcc -g -O2 -c cdata.c -o cdata.o `python-config --includes`
	gcc -g -O2 -shared -o cdata.so cdata.o `python-config --libs`
