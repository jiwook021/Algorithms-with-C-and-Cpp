CC = g++
CFLAGS  = -g -Wall
Language = cpp

Target1 = Video

main: main.o $(Target1).o 
	$(CC) $(CFLAGS) -o main main.o $(Target1).o 
 
main.o: main.$(Language) $(Target1).h 
	$(CC) $(CFLAGS) -c main.$(Language)
 
$(Target1).o: $(Target1).h 
  
clean:
	$(RM) $(Target)
	$(RM) main