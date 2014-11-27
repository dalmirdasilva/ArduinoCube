#!/bin/bash

set -e
echo
echo "Installing Arduino Cube"
echo "======================="
echo

ARDUINO_LIB_PATH="/usr/share/arduino/libraries/"

declare -a CORE_LIBS=("Cube" "Point" "Voxel")
declare -a UTIL_LIBS=("Util")
declare -a EFFECT_LIBS=("Effect" "Blink" "GameOfLife" "Rain")

function install() {
  from=$1
  name=$2
  to=$ARDUINO_LIB_PATH$name
  echo "Installing $name"
  echo "Creating destination folder: $to"
  mkdir -p "$ARDUINO_LIB_PATH$name"
  rm -rf "$ARDUINO_LIB_PATH$name/*"
  echo "Coping: $from/$name.* to $to"
  cp $from/$name.* "$to"
  echo
}

for LIB in "${CORE_LIBS[@]}"
do
  install "src/core" "$LIB"
done

for LIB in "${UTIL_LIBS[@]}"
do
  install "src/util" "$LIB"
done

for LIB in "${EFFECT_LIBS[@]}"
do
  install "src/effect" "$LIB"
done

echo "Done."
