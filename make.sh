#!/bin/sh

podman run -v $PWD:/proj:z -it --rm swig bash -c 'cd /proj/src/main && make clean && make python'
