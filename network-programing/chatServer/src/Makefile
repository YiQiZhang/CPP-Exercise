CC		= g++
CFLAGS		= -g -c -Wall -std=c++11 -stdlib=libc++
LDFLAGS		= 
SOURCES		= server.cpp tcpconnector.cpp tcpstream.cpp tcpacceptor.cpp
INCLUDES	= -I.
OBJECTS		= $(SOURCES:.cpp=.o)
TARGET		= server

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

.PHONY : clean cleanobj
clean:
	rm -rf $(OBJECTS) $(TARGET)

cleanobj:
	rm -rf $(OBJECTS)