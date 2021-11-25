all: swig comp

swig:
	swig -Wall -c -c++ MNA.i

comp:
	g++ -shared -o _MNA.so -fPIC *.cc MNA_wrap.cxx `pkg-config --libs --cflags eigen3`

clean:
	rm -rf *.so *.o *_wrap.cxx *.py *.java *.pm *.lisp
