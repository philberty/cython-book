#!/bin/bash
set -e

echo "Building Chapter 1..."
pushd chapter1

  pushd helloworld
  make -f Makefile
  echo "[TEST]"
  python -c "import helloworld"
  popd

  echo

  pushd ownmodule
  make -f Makefile
  echo "[TEST]"
  python -c "import mycodepy"
  popd


  echo
popd

echo "Building Chapter 2..."
pushd chapter2

  pushd cpy-public
  make -f Makefile
  echo "[TEST]"
  ./publicTest
  popd

  echo

  pushd cpy-logging
  make -f Makefile
  echo "[TEST]"
  ./example log.file
  popd

  echo

  pushd cpy-configparser
  make -f Makefile
  echo "[TEST]"
  ./example sample.cfg
  popd

  echo

  pushd cpy-cdef-reference
  echo "[TEST]"
  make -f Makefile
  ./example
  popd

  echo

  pushd messaging-server
  cd server4
  make -f Makefile
  cd ../
  popd

  echo
popd


echo "Building Chapter 3..."
pushd chapter3

  pushd primes
  make -f Makefile
  echo "[TEST]"
  python pyprimes.py
  ./primes
  popd

  echo

  pushd memory
  make -f Makefile
  echo "[TEST]"
  python main.py
  popd

  echo

  pushd function-pointers
  make -f Makefile
  echo "[TEST]"
  ./fptrs
  popd

  echo

  pushd tmux-project
  cd tmux-1.8
  ./autogen.sh
  ./configure --prefix=$HOME --enable-python
  make
  cd ../
  popd

echo
popd

echo "Building chapter 4..."
pushd chapter4

  pushd bool
  make -f Makefile
  echo "[TEST]"
  ./test
  popd

  echo

  pushd exceptions
  make -f Makefile
  echo "[TEST]"
  ./test
  popd

  pushd pointer
  make -f Makefile
  echo "[TEST]"
  python main.py
  popd

echo
popd

echo "Building chapter 5..."
pushd chapter5

  pushd cppalloc
  make -f Makefile
  echo "[TEST]"
  ./test
  popd

  pushd cppnamespace
  make -f Makefile
  echo "[TEST]"
  ./test
  popd

  pushd cppoverloading
  make -f Makefile
  echo "[TEST]"
  ./test
  popd

echo
popd