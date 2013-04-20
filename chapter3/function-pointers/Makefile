all:
	cython --embed -2 cpycode.pyx
	gcc -g -O2 -c cpycode.c -o cpycode.o `python-config --includes`
	gcc -g -O2 -c ccode.c -o ccode.o
	gcc -g -O2 -o fptrs cpycode.o ccode.o `python-config --libs`
