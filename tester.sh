#/bin/bash

current_dir=$(basename "$(pwd)")
target_dir="get_next_line"
tester1="gnlTester"

if [ "$current_dir" != "$target_dir" ]; then
	echo "Current directory is not $target_dir"
	exit 1
fi

if [ "$1" == "clean" ]; then
	rm -rf $tester1
	exit 1
fi

if [ ! -d "$tester1" ]; then
	git clone https://github.com/Tripouille/gnlTester.git
fi

# make -C $tester1 m;
make -C $tester1 b;

if [ "$1" == "testclean" ]; then
	rm -rf $tester1
fi
