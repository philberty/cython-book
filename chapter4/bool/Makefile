all:
	cython -2 cycode.pyx --embed
	g++ -g -O2 -c cycode.c -o cycode.o `python-config --includes`
	g++ -g -O2 -o test cycode.o `python-config --libs`
