# Compiler
CC = g++

# Compiler flags
CFLAGS ?= --std=c++11 -Wall -Werror -pedantic -g


Language = cpp

Target1 = Image
Target2 = Matrix
Target3 = processing

main: resize.o $(Target1).o $(Target2).o $(Target3).o 
	$(CC) $(CFLAGS) -o resize resize.o $(Target1).o $(Target2).o $(Target3).o 
 
main.o: resize.$(Language) $(Target1).h $(Target2).h $(Target3).h 
	$(CC) $(CFLAGS) -c resize.$(Language)
 
$(Target1).o: $(Target1).h $(Target2).h 
$(Target2).o: $(Target2).h 
$(Target3).o: $(Target1).h $(Target2).h $(Target3).h 
    
resize: resize.cpp Matrix.cpp Image.cpp processing.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@


# Run a regression test
test1: resize
	./resize dog.ppm dog45.ppm 4 5
test2: resize	
	./resize crabster.ppm crabster6030.ppm 60 30
test3: resize	
	./resize horses.ppm horses300200.ppm 300 200
	

clean: 
	$(RM) *.exe *.out.txt *.out.ppm *.dSYM *.stackdump *.o resize crabster6030.ppm horses300200.ppm dog45.ppm