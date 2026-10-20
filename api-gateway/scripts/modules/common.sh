#! /bin/bash

find_boost_dir_fn() {
  boost_dir="$(find "$HOME/.local" -name BoostConfig.cmake -printf '%h\n' -quit)"

  if [[ -z "$boost_dir" ]]; then
    echo "Error: BoostConfig.cmake not found under $HOME/.local" >&2
    return 1
  fi

  printf '%s\n' "$boost_dir"
}