CC = gcc
CFLAGS  = -g -Wall

Target1 = ArrayBaseStack
Target2 = CircularQueue
Target3 = DLinkedList
Target4 = Graph
Language = c

main: main.o $(Target1).o $(Target2).o $(Target3).o $(Target4).o  
	$(CC) $(CFLAGS) -o main main.o $(Target1).o $(Target2).o $(Target3).o $(Target4).o
 
main.o: main.$(Language) $(Target1).h $(Target2).h $(Target3).h $(Target4).h
	$(CC) $(CFLAGS) -c main.$(Language)
 
$(Target1).o: $(Target1).h 
$(Target2).o: $(Target2).h 
$(Target3).o: $(Target3).h
$(Target4).o: $(Target4).h $(Target2).h $(Target1).h 
  
clean:
	$(RM) $(Target1).o
	$(RM) $(Target2).o
	$(RM) $(Target3).o
	$(RM) $(Target4).o
	$(RM) main.o
	$(RM) main