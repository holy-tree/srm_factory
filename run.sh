#!/bin/bash
PROJECT_DIR="./Factory"

cd "Factory"||exit

mkdir -p build

cd build || exit

cmake ..
make

./product_factory
