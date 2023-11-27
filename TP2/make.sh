#!/bin/bash

g++ main.cpp appartement.cpp -o appartement

if [[ $* == *-run* ]]; then
    if [ $? -ne 0 ]; then
        exit
    fi
    ./appartement
fi