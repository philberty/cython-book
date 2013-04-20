all:
	cython -2 cycode.pyx
	gcc -g -O2 -fpic -c cycode.c -o cycode.o `python-config --includes`
	gcc -g -O2 -shared -o cycode.so cycode.o `python-config --libs`
