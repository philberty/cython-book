all:
	cython -2 -o mycodepy.c mycodepy.pyx
	gcc -g -O2 -fpic -c mycodepy.c -o mycodepy.o `python-config --cflags`
	gcc -g -O2 -fpic -c mycode.c -o mycode.o
	gcc -g -O2 -shared -o mycodepy.so mycode.o mycodepy.o

clean:
	rm -f *.o *.so *~ mycodepy.c
