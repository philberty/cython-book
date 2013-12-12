all:
	cython --embed -2 -o mycodepy.c mycodepy.pyx
	gcc -g -O2 -c mycodepy.c -o mycodepy.o `python-config --cflags`
	gcc -g -O2 -c mycode.c -o mycode.o
	gcc -g -O2 -o example mycode.o mycodepy.o `python-config --libs`

clean:
	rm -f *.o *.so *~ mycodepy.c
