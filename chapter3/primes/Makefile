all:
	cython --embed primes.pyx
	gcc -g -O2 -c primes.c -o primes.o `python-config --includes`
	gcc -g -O2 -o primes primes.o `python-config --libs`

test:
	time python pyprimes.py
	time ./primes

clean:
	rm -f *.o primes.c primes
