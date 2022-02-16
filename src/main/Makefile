CC=g++
PKGCONF=pkg-config
JAVA_HOME=/usr/lib/jvm/java-1.8.0-openjdk

EIGEN = -I../../lib/eigen/

all: java python c

java: swig_java comp_java

python: swig_python comp_python

c: swig_c comp_c

swig_c:
	mkdir -p c
	swig -Wall -c -c++ -outdir c -o c/MNA.cxx -oh c/MNA.h MNA.i

comp_c:
	${CC} -shared -o c/_MNA.so -I. -fPIC *.cc c/MNA.cxx ${EIGEN} -g
	rm c/MNA.cxx

swig_java:
	mkdir -p java
	swig -Wall -java -c++ -outdir java -package uk.co.therhys.MNA -o java/MNA.cxx MNA.i

comp_java:
	${CC} -shared -o java/libMNA.so -I. -fPIC *.cc java/MNA.cxx ${EIGEN} -I${JAVA_HOME}/include/ -I${JAVA_HOME}/include/linux -g
	rm java/MNA.cxx
	
swig_python:
	mkdir -p python
	swig -Wall -python -c++ -outdir python -o python/MNA.cxx MNA.i

comp_python:
	${CC} -shared -o python/_MNA.so -I. -fPIC *.cc python/MNA.cxx `${PKGCONF} --libs --cflags python3` ${EIGEN}
	rm python/MNA.cxx

swig_perl:
	mkdir -p perl
	swig -Wall -perl -c++ -outdir perl -o perl/MNA.cxx MNA.i

comp_perl:
	${CC} -shared -o perl/_MNA.so -I. -fPIC *.cc perl/MNA.cxx `perl -MConfig -e 'print $Config{libs}'` -I`perl -MConfig -e 'print $$Config{archlib}'`/CORE -L`perl -MConfig -e 'print $$Config{archlib}'`/CORE ${EIGEN}

install:
	mkdir -p /mnt/share/scripts/CircuitTesterJava/src/main/java/uk/co/therhys/MNA
	rm -f /mnt/share/scripts/CircuitTesterJava/src/main/java/uk/co/therhys/MNA/*
	cp java/*.so /mnt/share/scripts/CircuitTesterJava/src/main/java/uk/co/therhys/MNA/libMNA.so
	cp java/*.java /mnt/share/scripts/CircuitTesterJava/src/main/java/uk/co/therhys/MNA/

clean:
	rm -rf *.so *.o *_wrap.cxx *.py *.java *.pm *.lisp *.dll *.class *.pm c/ java/ python/
