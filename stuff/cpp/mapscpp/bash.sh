#!/bin/bash

function buildgcc() {
    touch src/main.cpp
    g++ -c *.cpp
    g++ *.o -o queue.out
}

function build() {
    touch src/main.cpp
    make
}

function run() {
    ./bin/main
}