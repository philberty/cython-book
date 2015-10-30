#!/usr/bin/env python

from PyData import Data


def TestPythonData():
    # Looks and feels like normal python objects
    objectList = [Data(1), Data(2), Data(3)]

    # Print them out
    for dataObject in objectList:
        print dataObject

    # Show the Mutability
    objectList[1].SetValue(1234)
    print objectList[1]

    # all native objects will be deallocated on close
    pass


if __name__ == "__main__":
    TestPythonData()
