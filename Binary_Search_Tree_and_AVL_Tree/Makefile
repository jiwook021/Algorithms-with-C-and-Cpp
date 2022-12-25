CC = g++
CFLAGS  = -g -Wall -std=c++17

Target1 = AVLRebalance
Target2 = Binary_Search_Tree
Target3 = Binary_tree
main = main
Language = cpp

main: $(main).o $(Target1).o $(Target2).o $(Target3).o 
	$(CC) $(CFLAGS) -o main main.o $(Target1).o $(Target2).o $(Target3).o
 
main.o: $(main).$(Language) $(Target1).hpp $(Target2).hpp $(Target3).h
	$(CC) $(CFLAGS) -c $(main).$(Language)
 
$(Target1).o: $(Target1).hpp $(Target2).hpp $(Target3).h
$(Target2).o: $(Target2).hpp $(Target2).hpp
$(Target3).o: $(Target3).h

clean:
	$(RM) $(Target)
	$(RM) $(Target2)
	$(RM) $(Target3)
	$(RM) $(Target).o
	$(RM) $(Target2).o
	$(RM) $(Target3).o
	$(RM) main