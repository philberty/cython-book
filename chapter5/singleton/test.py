#!/usr/bin/env python

import PySingleton as cpplib

test = cpplib.PyMySingleton.getInstance()

print test.value
test.value = 5678
print test.value

print test.doSomething(1)
