all:
	cython --embed -2 cycode.pyx
	gcc -g -O2 cycode.c -o test `python-config --includes --libs`
