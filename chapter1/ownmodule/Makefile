all:
	cython mycodepy.pyx
	gcc -g -O2 -fpic -c mycodepy.c -o mycodepy.o `python-config --includes`
	gcc -g -O2 -fpic -c mycode.c -o mycode.o
	gcc -g -O2 -shared -o mycodepy.so mycodepy.o mycode.o `python-config --libs`

clean:
	rm -f mycodepy.c *.o *.so
