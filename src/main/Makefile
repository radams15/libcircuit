all: lin

lin: swig lcomp
	cp _MNA.so /home/ubuntu/scripts/CircuitTester/lib/MNA/libMNA.so
	cp MNA_wrap.h /home/ubuntu/scripts/CircuitTester/lib/MNA/MNA.h

win: swig wcomp

swig:
	swig -Wall -c -c++ MNA.i

lcomp:
	g++ -shared -o _MNA.so -fPIC *.cc MNA_wrap.cxx `pkg-config --libs --cflags eigen3` -g

wcomp:
	x86_64-w64-mingw32-g++ -shared -o _MNA.dll -fPIC *.cc MNA_wrap.cxx `x86_64-w64-mingw32-pkg-config --libs --cflags eigen3`

clean:
	rm -rf *.so *.o *_wrap.cxx *.py *.java *.pm *.lisp *.dll
