CC = g++
CFLAGS  = -g -Wall

Target1 = AVLRebalance
Target2 = Binary_Search_Tree
Target3 = Binary_Tree
Language = cpp

main: main.o $(Target1).o $(Target2).o $(Target3).o 
	$(CC) $(CFLAGS) -o main main.o $(Target1).o $(Target2).o $(Target3).o
 
main.o: main.$(Language) $(Target1).hpp $(Target2).hpp $(Target3).hpp
	$(CC) $(CFLAGS) -c main.$(Language)
 
$(Target1).o: $(Target1).hpp $(Target2).hpp $(Target3).hpp
$(Target2).o: $(Target2).hpp $(Target2).hpp
$(Target3).o: $(Target3).hpp
  
clean:
	$(RM) $(Target)
	$(RM) $(Target2)
	$(RM) $(Target3)
	$(RM) $(Target).o
	$(RM) $(Target2).o
	$(RM) $(Target3).o
	$(RM) main