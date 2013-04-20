all:
	cython -2 --cplus testvec.pyx
	cython -2 --cplus testmap.pyx
	g++ -g -O2 -fpic -c testvec.cpp -o testvec.o `python-config --includes`
	g++ -g -O2 -fpic -c testmap.cpp -o testmap.o `python-config --includes`
	g++ -g -O2 -shared -o testvec.so testvec.o `python-config --libs`
	g++ -g -O2 -shared -o testmap.so testmap.o `python-config --libs`
