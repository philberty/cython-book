all:
	cython cdata.pyx
	gcc -g -O2 -fPIC -c cdata.c -o cdata.o `python-config --includes`
	gcc -g -O2 -shared -o cdata.so cdata.o `python-config --libs`
