#!/bin/bash

apt-get update -y && apt install build-essential gcc g++ python3 cmake make lcov -y 
apt update -y && apt install python3-pip -y
pip3 install conan
conan profile detect
