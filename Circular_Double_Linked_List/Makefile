CC = gcc
CFLAGS  = -g
Language = c

Target1 = Circular_doublelinkedlist


main: main.o $(Target1).o 
	$(CC) $(CFLAGS) -o main main.o $(Target1).o 
 
main.o: main.$(Language) $(Target1).h 
	$(CC) $(CFLAGS) -c main.$(Language)
 
$(Target1).o: $(Target1).h 
  
clean:
	$(RM) $(Target1).o
	$(RM) main.o
	$(RM) main