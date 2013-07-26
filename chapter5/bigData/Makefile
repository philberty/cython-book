all:
	cython -2 cpyparse.py --embed
	gcc -g -O2 -c cpyparse.c -o cpyparse.o `python-config --includes`
	gcc -g -O2 -o cpyparse cpyparse.o `python-config --libs`