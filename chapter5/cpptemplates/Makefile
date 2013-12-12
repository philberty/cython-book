all:
	g++ -g -O2 -fpic -c cppcode.cc -o cppcode.o
	cython -2 --embed --cplus cpycode.pyx
	g++ -g -O2 -fpic -c cpycode.cpp -o cpycode.o `python-config --includes`
	g++ -g -O2 -o test cpycode.o cppcode.o `python-config --libs`
