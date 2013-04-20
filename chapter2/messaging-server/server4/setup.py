from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

setup(
    scripts = ['messagingServer.py'],
    packages = ['messagingEngine'],
    cmdclass = { 'build_ext' : build_ext },
    ext_modules = [ Extension ("pyserver", ["pyserver.pyx", "server.c" ]) ]
)
