all:
	cython -2 PyData.pyx
	gcc -g -O2 -fPIC -c PyData.c -o PyData.o `python-config --includes`
	gcc -g -O2 -shared -o PyData.so PyData.o `python-config --libs`

clean:
	rm -rf *.o *.so PyData.c
