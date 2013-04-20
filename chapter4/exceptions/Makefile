all:
	cython -2 cycode.pyx
	gcc -g -O2 -c cycode.c -o cycode.o `python-config --includes`
	gcc -g -O2 -c main.c -o main.o `python-config --includes`
	gcc -g -O2 -o test cycode.o main.o `python-config --libs`
