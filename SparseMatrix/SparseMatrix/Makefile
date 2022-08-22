CC = gcc
CFLAGS =-g -Wall

Target1 = Circular_Linked_List
Target2 = LinkedList
Target3 = SparseMatrix
Language = c

main: main.o $(Target1).o $(Target2).o $(Target3).o 
	$(CC) $(CFLAGS) -o main main.o $(Target1).o $(Target2).o $(Target3).o
 
main.o: main.$(Language) $(Target1).h $(Target2).h $(Target3).h
	$(CC) $(CFLAGS) -c main.$(Language)
 
$(Target1).o: $(Target1).h 
$(Target2).o: $(Target2).h 
$(Target3).o: $(Target3).h $(Target2).h 
  
clean:
	$(RM) $(Target1).o
	$(RM) $(Target2).o
	$(RM) $(Target3).o
	$(RM) main.o