import sys
from xml.etree import ElementTree as etree

__xmlFile = 'EPAXMLDownload.xml'
__output = 'xmlout.dat'

def info (msg): print "[INFO] %s" % msg

def outputData (headers, facs):
    assert len (headers) == 1
    for i in headers[0]: print i.text
    info ("Number of Facilties %i" % len (facs))
    info ("Dumping facilities to %s" % __output)
    try:
        fd = open (__output, "wb")
        for i in facs:
            location = ""
            for y in i:
                if isinstance (y.text, basestring):
                    location += y.tag + ": " + y.text + '\n'
            fd.write (location)
    # There is some dodgy unicode character
    # python doesn't like just ignore it
    except UnicodeEncodeError: pass
    except:
        print "Unexpected error:", sys.exc_info()[0]
        raise
    finally:
        if fd: fd.close ()

def parseData ():
    xmlroot = etree.parse (__xmlFile)
    headers = xmlroot.findall ('Header')
    facs = xmlroot.findall ('FacilitySite')
    outputData (headers, facs)
    del headers, facs, xmlroot

if __name__ == "__main__":
    parseData ()
