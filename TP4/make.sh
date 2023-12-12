#!/bin/bash

g++ main.cpp rat.cpp -o TP4

if [[ $* == *-run* ]]; then
    if [ $? -ne 0 ]; then
        exit
    fi
    ./TP4
fi