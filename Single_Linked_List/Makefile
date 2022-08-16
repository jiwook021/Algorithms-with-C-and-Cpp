CC = g++
CFLAGS  =-g -Wall

Target1 = Linked_List
Target2 = function
Language = cpp

main: main.o $(Target1).o $(Target2).o 
	$(CC) $(CFLAGS) -o main main.o $(Target1).o $(Target2).o 
 
main.o: main.$(Language) $(Target1).hpp
	$(CC) $(CFLAGS) -c main.$(Language)
 
$(Target1).o: $(Target1).hpp
$(Target2).o: $(Target1).hpp
 
clean:
	$(RM) $(Target1).o
	$(RM) $(Target2).o
	$(RM) main.o
	$(RM) main