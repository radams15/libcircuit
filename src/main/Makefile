CC=g++
PKGCONF=pkg-config
JAVA_HOME=/usr/lib/jvm/java-11-openjdk-amd64

all: java python c

java: swig_java comp_java

python: swig_python comp_python

c: swig_c comp_c

go: swig_go

cpp:
	mkdir -p cpp
	cp ../../api/* cpp
	${CC} -shared -o cpp/_MNA.so -I. -fPIC *.cc `${PKGCONF} --libs --cflags eigen3` -g

swig_go:
	mkdir -p go
	swig -Wall -go -c++ -outdir go -o go/MNA.cxx -intgosize 32 MNA.i

comp_go:
	${CC} -shared -o go/_MNA.so -I. -fPIC *.cc go/MNA.cxx `${PKGCONF} --libs --cflags eigen3` -g
	rm go/MNA.cxx


swig_c:
	mkdir -p c
	swig -Wall -c -c++ -outdir c -o c/MNA.cxx -oh c/MNA.h MNA.i

comp_c:
	${CC} -shared -o c/_MNA.so -I. -fPIC *.cc c/MNA.cxx `${PKGCONF} --libs --cflags eigen3` -g
	rm c/MNA.cxx

swig_java:
	mkdir -p java
	swig -Wall -java -c++ -outdir java -o java/MNA.cxx MNA.i

comp_java:
	${CC} -shared -o java/_MNA.so -I. -fPIC *.cc java/MNA.cxx `${PKGCONF} --libs --cflags eigen3` -I${JAVA_HOME}/include/ -I${JAVA_HOME}/include/linux -g
	rm java/MNA.cxx
	
swig_python:
	mkdir -p python
	swig -Wall -python -c++ -outdir python -o python/MNA.cxx MNA.i

comp_python:
	${CC} -shared -o python/_MNA.so -I. -fPIC *.cc python/MNA.cxx `${PKGCONF} --libs --cflags eigen3 python3`
	rm python/MNA.cxx

swig_perl:
	mkdir -p perl
	swig -Wall -perl -c++ -outdir perl -o perl/MNA.cxx MNA.i

comp_perl:
	${CC} -shared -o perl/_MNA.so -I. -fPIC *.cc perl/MNA.cxx `perl -MConfig -e 'print $Config{libs}'` -I`perl -MConfig -e 'print $$Config{archlib}'`/CORE -L`perl -MConfig -e 'print $$Config{archlib}'`/CORE `${PKGCONF} --libs --cflags eigen3`

install:
	mkdir -p /home/rhys/scripts/CircuitTester/lib/MNA/
	cp c/_MNA.so /home/rhys/scripts/CircuitTester/lib/MNA/libMNA.so
	cp c/MNA.h /home/rhys/scripts/CircuitTester/lib/MNA/

clean:
	rm -rf *.so *.o *_wrap.cxx *.py *.java *.pm *.lisp *.dll *.class *.pm c/ java/ python/
