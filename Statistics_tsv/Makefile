CC = g++
CFLAGS  = -g -Wall -std=c++17

Target1 = p1_library
Target2 = stats
main = main
Language = cpp

main: $(main).o $(Target1).o $(Target2).o 
	$(CC) $(CFLAGS) -o main main.o $(Target1).o $(Target2).o 
 
main.o: $(main).$(Language) $(Target1).h $(Target2).h 
	$(CC) $(CFLAGS) -c $(main).$(Language)

Target1.o: $(Target1).$(Language) $(Target1).h $(Target2).h 
	$(CC) $(CFLAGS) -c $(Target1).$(Language)

$(Target1).o: $(Target1).h $(Target2).h
$(Target2).o: $(Target1).h $(Target2).h

test: main
	./main main_test_data.tsv B
test1: main
	./main main_test_data.tsv A
test2: main
	./main main_test_data.tsv B

clean:
	$(RM) $(Target1).o
	$(RM) $(Target2).o
	$(RM) main.o
	$(RM) main