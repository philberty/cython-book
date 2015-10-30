all:
	cython -2 PyAddFunction.pyx
	gcc -g -O2 -fpic -c PyAddFunction.c -o PyAddFunction.o `python-config --includes`
	gcc -g -O2 -fpic -c AddFunction.c -o AddFunction.o
	gcc -g -O2 -shared -o PyAddFunction.so AddFunction.o PyAddFunction.o `python-config --libs`

clean:
	rm -f PyAddFunction.c *.o *.so
