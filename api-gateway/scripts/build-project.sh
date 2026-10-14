#! /bin/bash

set -euo pipefail
source "$(dirname "${BASH_SOURCE[0]}")/modules/common.sh"

boost_dir="$(find_boost_dir_fn)"
echo "Found Boost Cmake config: $boost_dir"

cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
  -DBoost_DIR="$boost_dir"
