CC		= g++
CFLAGS		= -g -c -Wall -std=c++11 -stdlib=libc++
LDFLAGS		= 
SOURCES		= example.cpp example1.cpp
INCLUDES	= -I.
OBJECTS		= $(SOURCES:.cpp=.o)
TARGET		= example.out example1.out

all: $(SOURCES) $(TARGET)

.o.out:
	$(CC) $(LDFLAGS) $< -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

.PHONY : clean cleanobj
clean:
	rm -rf $(OBJECTS) $(TARGET)

cleanobj:
	rm -rf $(OBJECTS)