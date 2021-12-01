CC=g++
PKGCONF=pkg-config

all: swig_java swig_python comp_java comp_python

swig_java:
	mkdir -p java
	swig -Wall -java -c++ -outdir java -o java/MNA.cxx MNA.i

comp_java:
	${CC} -shared -o java/_MNA.so -I. -fPIC *.cc java/MNA.cxx `${PKGCONF} --libs --cflags eigen3` -I/usr/lib/jvm/default-java/include/ -I/usr/lib/jvm/default-java/include/linux -g
	
swig_python:
	mkdir -p python
	swig -Wall -python -c++ -outdir python -o python/MNA.cxx MNA.i

comp_python:
	${CC} -shared -o python/_MNA.so -I. -fPIC *.cc python/MNA.cxx `${PKGCONF} --libs --cflags eigen3 python3` -g

swig_perl:
	mkdir -p perl
	swig -Wall -perl -c++ -outdir perl -o perl/MNA.cxx MNA.i

comp_perl:
	${CC} -shared -o perl/_MNA.so -I. -fPIC *.cc perl/MNA.cxx `perl -MConfig -e 'print $Config{libs}'` -I`perl -MConfig -e 'print $$Config{archlib}'`/CORE -L`perl -MConfig -e 'print $$Config{archlib}'`/CORE `${PKGCONF} --libs --cflags eigen3` -g

clean:
	rm -rf *.so *.o *_wrap.cxx *.py *.java *.pm *.lisp *.dll *.class *.pm
