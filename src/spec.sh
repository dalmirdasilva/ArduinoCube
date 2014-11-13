#!/bin/bash

make clean
make && time ./spec
make clean
