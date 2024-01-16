#!/bin/bash

c++ -o orthodox_generator $HOME/Orthodox_maker/program.cpp
./orthodox_generator "$@"
if [ $? -eq 1 ]; then
    echo "Failed"
    rm orthodox_generator
else
    echo "DONE ✅"
    rm orthodox_generator
fi
