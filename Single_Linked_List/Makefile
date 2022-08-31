CC = g++
CFLAGS  =-g -Wall

Target1 = Linked_List
Language = cpp

main: main.o $(Target1).o
	$(CC) $(CFLAGS) -o main main.o $(Target1).o
 
main.o: main.$(Language) $(Target1).hpp
	$(CC) $(CFLAGS) -c main.$(Language)
 
$(Target1).o: $(Target1).hpp
 
clean:
	$(RM) $(Target1).o
	$(RM) main.o
	$(RM) main