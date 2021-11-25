FROM fedora:34

RUN dnf in -y autoconf automake git gcc gcc-c++ bison pcre-devel make

RUN dnf -y in mingw64-gcc mingw64-gcc-c++ mingw64-eigen3

RUN git clone https://github.com/vadz/swig/ && cd swig && git checkout C
RUN cd swig && ./autogen.sh && ./configure --prefix=/usr
RUN cd swig && make && make install
