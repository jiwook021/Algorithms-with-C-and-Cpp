CC = g++
CFLAGS  = -g -Wall

Target1 = ALEdge
Target2 = ALGraphKruskal
Target3 = ArrayBaseStack
Target4 = DLinkedList
Target5 = PriorityQueue
Target6 = UsefulHeap
Language = cpp

main: KruskalMain.o $(Target2).o $(Target3).o $(Target4).o $(Target5).o $(Target6).o  
	$(CC) $(CFLAGS) -o main KruskalMain.o $(Target2).o $(Target3).o $(Target4).o $(Target5).o $(Target6).o
 
main.o: KruskalMain.$(Language) $(Target1).h $(Target2).h $(Target3).h $(Target4).h $(Target5).h $(Target6).h
	$(CC) $(CFLAGS) -c KruskalMain.$(Language)
 

$(Target2).o: $(Target1).h $(Target2).h $(Target3).h $(Target4).h
$(Target3).o: $(Target3).h
$(Target4).o: $(Target4).h
$(Target5).o: $(Target5).h $(Target6).h
$(Target6).o: $(Target6).h
   
clean:
	$(RM) $(Target)
	$(RM) $(Target2)
	$(RM) $(Target3)
	$(RM) $(Target4)
	$(RM) $(Target5)
	$(RM) $(Target6)
	$(RM) $(Target2).o
	$(RM) $(Target3).o
	$(RM) $(Target4).o
	$(RM) $(Target5).o
	$(RM) $(Target6).o
	$(RM) KruskalMain.o
	$(RM) KruskalMain
	$(RM) KruskalMain.exe