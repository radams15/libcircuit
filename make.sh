#!/bin/sh

cd src/main

make clean
make lin

podman run -v $PWD:/proj -it --rm swig bash -c 'cd /proj && make win'
