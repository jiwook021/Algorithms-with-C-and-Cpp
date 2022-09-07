CC = g++
CFLAGS  = -g -Wall -std=c++17
Language = cpp

Target1 = unique_pointers
Target2 = shared_pointers
Target3 = weak_pointers
Target4 = legacy_shared_pointer
main:
	$(CC) $(CFLAGS) $(Target1).$(Language) -o $(Target1)
	$(CC) $(CFLAGS) $(Target2).$(Language) -o $(Target2)
	$(CC) $(CFLAGS) $(Target3).$(Language) -o $(Target3)
	$(CC) $(CFLAGS) $(Target4).$(Language) -o $(Target4)
clean:
	$(RM) $(Target1)
	$(RM) $(Target2)
	$(RM) $(Target3)
	$(RM) $(Target4)