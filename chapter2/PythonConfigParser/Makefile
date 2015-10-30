all:
	cython -2 PythonConfigParser.pyx
	gcc -g -O2 -fpic -c PythonConfigParser.c -o PythonConfigParser.o `python-config --includes`
	gcc -g -O2 -fpic -c main.c -o main.o `python-config --includes`
	gcc -g -O2 -o example main.o PythonConfigParser.o `python-config --libs`

clean:
	rm -f example PythonConfigParser.{c,h} *.o
