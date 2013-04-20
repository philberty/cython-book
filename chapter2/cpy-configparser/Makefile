all:
	cython config.pyx
	gcc -g -O2 -fpic -c config.c -o config.o `python-config --includes`
	gcc -g -O2 -fpic -c main.c -o main.o `python-config --includes`
	gcc -g -O2 -o example main.o config.o `python-config --libs`

clean:
	rm -f example config.c *.o
