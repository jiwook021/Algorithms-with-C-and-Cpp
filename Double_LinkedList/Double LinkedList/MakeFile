CC = g++
CFLAGS  = -g -Wall
Language = cpp

Target1 = doublelinkedlist


main: main.o $(Target1).o 
	$(CC) $(CFLAGS) -o main main.o $(Target1).o 
 
main.o: main.$(Language) $(Target1).hpp 
	$(CC) $(CFLAGS) -c main.$(Language)
 
$(Target1).o: $(Target1).hpp 
  
clean:
	$(RM) $(Target)
	$(RM) main