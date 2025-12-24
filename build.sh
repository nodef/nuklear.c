#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -d "nuklear" ]; then return; fi
URL="https://github.com/Immediate-Mode-UI/Nuklear/raw/refs/heads/master/nuklear.h"
FILE="nuklear.h"

# Download the release
echo "Downloading $FILE from $URL ..."
mkdir -p nuklear
curl -L "$URL" -o "nuklear/$FILE"
echo ""
}


# Test the project
test() {
# echo "Running 01-basic-window.c ..."
# clang -I. -o 01.exe examples/01-basic-window.c         && ./01.exe && echo -e "\n"
# echo "Running 02-layouts.c ..."
# clang -I. -o 02.exe examples/02-layouts.c              && ./02.exe && echo -e "\n"
# echo "Running 03-slider-and-progress.c ..."
# clang -I. -o 03.exe examples/03-slider-and-progress.c  && ./03.exe && echo -e "\n"
# echo "Running 04-tabs.c ..."
# clang -I. -o 04.exe examples/04-tabs.c                 && ./04.exe && echo -e "\n"
# echo "Running 05-custom-widgets.c ..."
# clang -I. -o 05.exe examples/05-custom-widgets.c       && ./05.exe && echo -e "\n"
# echo "Running 06-drag-and-drop.c ..."
# clang -I. -o 06.exe examples/06-drag-and-drop.c        && ./06.exe && echo -e "\n"
# echo "Running 07-complex-ui.c ..."
# clang -I. -o 07.exe examples/07-complex-ui.c           && ./07.exe && echo -e "\n"
echo "Running 08-demo.c ..."
clang -I. -o 08.exe examples/08-demo.c         && ./08.exe && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
