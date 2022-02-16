FROM docker.io/fedora:25

RUN dnf install -y autoconf automake git gcc gcc-c++ bison pcre-devel make

RUN dnf install -y mingw32-gcc mingw32-gcc-c++

RUN git clone https://github.com/vadz/swig/ && cd swig && git checkout C
RUN cd swig && ./autogen.sh && ./configure --prefix=/usr
RUN cd swig && make && make install

RUN dnf install -y libstdc++-static java-1.8.0-openjdk-devel python3-devel
