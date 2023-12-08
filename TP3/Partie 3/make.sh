#!/bin/bash

g++ appartement.cpp main.cpp piece.cpp -o TP3-p3

if [[ $* == *-run* ]]; then
    if [ $? -ne 0 ]; then
        exit
    fi
    ./TP3-p3
fi