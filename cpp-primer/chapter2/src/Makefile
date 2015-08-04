CC			= g++
CFLAGS		= -g -c -Wall
LDFLAGS		= 
SOURCES		= 
INCLUDES	= -I.
OBJECTS		= $(SOURCES:.cpp=.o)
TARGET		= 


a : a.o helloworld.o 
	$(CC) -o a a.o helloworld.o 

a.o : helloworld.h
	$(CC) -c a.cpp

helloworld.o : helloworld.h
	$(CC) -c helloworld.cpp

clean:
	rm -rf a *.o