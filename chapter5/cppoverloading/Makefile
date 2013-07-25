all:
	g++ -g -O2 -c cppcode.cc -o cppcode.o
	cython -2 --cplus cpycode.pyx --embed
	g++ -g -O2 -c cpycode.cpp -o cpycode.o `python-config --includes`
	g++ -g -O2 -o test cpycode.o cppcode.o `python-config --libs`
