all:
	cython -2 --cplus PySingleton.pyx
	g++ -g -O2 -Wall -fpic -c PySingleton.cpp -o PySingleton.o `python-config --includes`
	g++ -g -O2 -shared -o PySingleton.so PySingleton.o `python-config --libs`

clean:
	rm -rf PySingleton.cpp PySingleton.o PySingleton.so
