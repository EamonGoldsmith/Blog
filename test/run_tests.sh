#!/bin/sh

echo building libraries...
gcc -I./src -o obj/binary_tree.o -c src/binary_tree.c
gcc -I./src -o obj/binary_tree_test.o -c test/binary_tree_test.c

echo linking...
gcc obj/binary_tree_test.o obj/binary_tree.o -o bin/binary_tree_test

echo tests ready in bin/