CC = g++
CFLAGS  =-g -Wall

Target1 = Linked_List
Target2 = function
Language = cpp

main: main.o $(Target1).o $(Target2).o 
	$(CC) $(CFLAGS) -o main main.o $(Target1).o $(Target2).o 
 
main.o: main.$(Language) $(Target1).h 
	$(CC) $(CFLAGS) -c main.$(Language)
 
$(Target1).o: $(Target1).h $
$(Target2).o: $(Target1).h 
 
clean:
	$(RM) $(Target)
	$(RM) $(Target2)
	$(RM) main