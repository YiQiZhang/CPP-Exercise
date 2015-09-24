CC		= clang++
CFLAGS		= -g -c -Wall -std=c++11 -stdlib=libc++
LDFLAGS		= 
SOURCES		= testlist.cpp testSTLList.cpp polynomial.cpp testPolynomial.cpp
INCLUDES	= -I.
OBJECTS		= $(SOURCES:.cpp=.o)
TARGET		= testlist testSTLList testPolynomial

testlist: testlist.o 

testSTLList: testSTLList.o 

testSTLList.o : testSTLList.cpp

testPolynomial: testPolynomial.o polynomial.o

$(OBJECTS): $(SOURCES) 
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

.PHONY : clean cleanobj
clean:
	rm -rf $(OBJECTS) $(TARGET)

cleanobj:
	rm -rf $(OBJECTS)