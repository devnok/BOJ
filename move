#!/bin/bash
s="solving"
v=$1
r=${v//[0-9]/}
if [ -z "$r" ]; then
  let f=v/100*100
  f=$(printf %05d $f)
else
  f=others
fi
echo $f
mkdir -p "AC/$f"
mv "$s/$v.cpp" "AC/$f/$v.cpp"