all:
	cython logger.pyx
	gcc -g -O2 -fpic -c logger.c -o logger.o `python-config --includes`
	gcc -g -O2 -fpic -c main.c -o main.o `python-config --includes`
	gcc -g -O2 -o example main.o logger.o `python-config --libs`

clean:
	rm -f example logger.c *.o
