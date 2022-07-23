# Compiler
CXX ?= g++

# Compiler flags
CXXFLAGS ?= --std=c++11 -Wall -Werror -pedantic -g

# Run a regression test
test: resize.exe
	resize.exe crabster.ppm crabster11.ppm 30 45
	


resize.exe: resize.cpp Matrix.cpp Image.cpp processing.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Disable built-in Makefile rules
.SUFFIXES:

clean:
	del /f *.exe *.out.txt *.out.ppm *.dSYM *.stackdump

	