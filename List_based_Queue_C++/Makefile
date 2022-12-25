CC = g++
CFLAGS  = -g -Wall
Language = cpp
Header = h
Target1 = LB_queue

main: main.o $(Target1).o 
	$(CC) $(CFLAGS) -o main main.o $(Target1).o 
 
main.o: main.$(Language) $(Target1).$(Header) 
	$(CC) $(CFLAGS) -c main.$(Language)
 
$(Target1).o: $(Target1).$(Header)
  
clean:
	$(RM) $(Target1).o
	$(RM) main.o
	$(RM) main