#!/bin/bash
mkdir -p "AC/$1"
mv "$1"/*.cpp AC/"$1"/
rmdir $1