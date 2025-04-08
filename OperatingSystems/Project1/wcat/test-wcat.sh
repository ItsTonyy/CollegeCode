#! /bin/bash

if [[ -x wcat ]]; then
    executable=./wcat
elif [[ -x wcat.exe ]]; then
    executable=./wcat.exe
else
    echo "wcat executable does not exist"
    exit 1
fi

../tester/run-tests.sh "$executable" $*


