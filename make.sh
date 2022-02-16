#!/bin/sh

podman run -v $PWD:/proj -it --rm swig bash -c 'ls /proj ;cd /proj/src/main && make c'
