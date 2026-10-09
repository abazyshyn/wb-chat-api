#! /bin/bash

cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
  -DBoost_DIR="$HOME/.local/lib/cmake/Boost-1.93.0"
