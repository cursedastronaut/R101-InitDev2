#!/bin/bash

g++ main.cpp permis.cpp -o permis

if [[ $* == *-run* ]]; then
    if [ $? -ne 0 ]; then
        exit
    fi
    ./permis
fi