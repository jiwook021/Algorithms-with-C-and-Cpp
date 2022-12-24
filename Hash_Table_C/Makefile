CC = gcc
CFLAGS  = -g -Wall
Language = c

Target1 = Hash_Table

main: main.o $(Target1).o 
	$(CC) $(CFLAGS) -o main main.o $(Target1).o 
 
main.o: main.$(Language) $(Target1).h 
	$(CC) $(CFLAGS) -c main.$(Language)
 
$(Target1).o: $(Target1).h 
  
clean:
	$(RM) $(Target1).o
	$(RM) main.o
	$(RM) main
	$(RM) main.exe