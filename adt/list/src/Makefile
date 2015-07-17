CC		= g++
CFLAGS		= -g -c -Wall
LDFLAGS		= 
SOURCES		= testlist.cpp list.cpp
INCLUDES	= -I.
OBJECTS		= $(SOURCES:.cpp=.o)
TARGET		= testlist

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