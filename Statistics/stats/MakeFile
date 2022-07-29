CC = g++
CFLAGS  = -g -Wall
Language = cpp

Target1 = p1_library
Target2 = stats


main: main.o  
	$(CC) $(CFLAGS) -o main main.o  

main.o: main.$(Language) $(Target1).h $(Target2).h 
	$(CC) $(CFLAGS) -c main.$(Language)

clean:
	$(RM) $(Target)
	$(RM) main

	