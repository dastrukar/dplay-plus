#!/bin/sh -x

compile:
	@echo "Compiling to 'bin/'"
	@g++ main.cpp -o bin/dplay+
	@echo "Done."
