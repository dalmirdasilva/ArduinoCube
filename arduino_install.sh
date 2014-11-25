#!/bin/bash

set -e
echo
echo "Installing Arduino Cube"
echo "======================="
echo

ARDUINO_LIB_PATH="/usr/share/arduino/libraries/"

declare -a LIBRARIES=("Cube" "Point" "Util" "Voxel")
declare -a EFFECTS=("Effect" "Blink" "GameOfLife" "Rain")

function install() {
  from=$1
  name=$2
  to=$ARDUINO_LIB_PATH$name
  echo "Installing $name"
  echo "Creating destination folder: $to."
  mkdir -p "$ARDUINO_LIB_PATH$name"
  rm -rf "$ARDUINO_LIB_PATH$name/*"
  echo "Coping: $from/$name.* to $to"
  cp $from/$name.* "$to"
  echo
}

for LIB in "${LIBRARIES[@]}"
do
  install "src" "$LIB"
done

for EFFECT in "${EFFECTS[@]}"
do
  install "src/effects" "$EFFECT"
done
