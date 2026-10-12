#! /bin/bash

set -euo pipefail

boost_dir="$(find "$HOME/.local" -name BoostConfig.cmake -printf '%h\n' -quit)"

if [[ -z "$boost_dir" ]]; then
  echo "Error: BoostConfig.cmake not found under $HOME/.local" >&2
  exit 1
fi

echo "Found Boost Cmake config: $boost_dir"

cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
  -DBoost_DIR="$boost_dir"

bear -- ninja -C build --verbose
