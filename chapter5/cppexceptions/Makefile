all:
	g++ -g -O2 -fpic -c cppcode.cc -o cppcode.o
	cython -2 --cplus cpycode.pyx
	g++ -g -O2 -fpic -c cpycode.cpp -o cpycode.o `python-config --includes`
	g++ -g -O2 -shared -o cpycode.so cpycode.o cppcode.o `python-config --libs`
