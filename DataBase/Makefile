CC = g++
CFLAGS  = -g -Wall -std=c++17

main = database
Target1 = personal
Language = cpp
header = hpp

main: $(main).o $(Target1).o  
	$(CC) $(CFLAGS) -o main $(Target1).o $(main).o

main.o: $(main).$(Language) $(main).hpp $(Target1).hpp
	$(CC) $(CFLAGS) -c $(main).$(Language)
 
$(main).o: $(main).hpp $(Target1).hpp 
$(Target1).o: $(Target1).hpp 

clean:
	$(RM) $(Target1).o
	$(RM) main