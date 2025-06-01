#! /bin/bash

if [[ -x wgrep ]]; then
    executable=./wgrep
elif [[ -x wgrep.exe ]]; then
    executable=./wgrep.exe
else
    echo "wgrep executable does not exist"
    exit 1
fi

../tester/run-tests.sh "$executable" $*