CC		= g++
CFLAGS		= -g -c -Wall -std=c++11 -stdlib=libc++
LDFLAGS		= 
SOURCES		= testlist.cpp testSTLList.cpp
INCLUDES	= -I.
OBJECTS		= $(SOURCES:.cpp=.o)
TARGET		= testlist testSTLList

all: $(SOURCES) $(TARGET)

testlist: testlist.o
	$(CC) $(LDFLAGS) testlist.o -o testlist

testSTLList: testSTLList.o
	$(CC) $(LDFLAGS) testSTLList.o -o testSTLList

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

.PHONY : clean cleanobj
clean:
	rm -rf $(OBJECTS) $(TARGET)

cleanobj:
	rm -rf $(OBJECTS)