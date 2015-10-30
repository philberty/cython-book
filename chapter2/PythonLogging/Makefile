all:
	cython -2 PythonLoggingBackend.pyx
	gcc -g -O2 -fpic -c PythonLoggingBackend.c -o PythonLoggingBackend.o `python-config --includes`
	gcc -g -O2 -fpic -c NativeLogging.c -o NativeLogging.o  `python-config --includes`
	gcc -g -O2 -fpic -c main.c -o main.o
	gcc -g -O2 -o example main.o PythonLoggingBackend.o NativeLogging.o `python-config --libs`

clean:
	rm -f example PythonLoggingBackend.{c,h} *.o
