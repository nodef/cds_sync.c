#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -f "cds_sync.h" ]; then return; fi
URL="https://github.com/cdwfs/cds_sync/raw/refs/heads/master/cds_sync.h"
FILE="cds_sync.h"

# Download the release
echo "Downloading $FILE from $URL ..."
curl -L "$URL" -o "$FILE"
echo ""
}


# Test the project
test() {
echo "Running 01-futex_example.c ..."
clang -I. -o 01.exe examples/01-futex_example.c  && ./01.exe && echo -e "\n"
echo "Running 02-monitor_example.c ..."
clang -I. -o 02.exe examples/02-monitor_example.c    && ./02.exe && echo -e "\n"
echo "Running 03-barrier_example.c ..."
clang -I. -o 03.exe examples/03-barrier_example.c  && ./03.exe && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
