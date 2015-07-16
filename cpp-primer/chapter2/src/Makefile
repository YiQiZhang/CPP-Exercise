a : a.o helloworld.o 
	g++ -o a a.o helloworld.o 

a.o : helloworld.h
	g++ -c a.cpp

helloworld.o : helloworld.h
	g++ -c helloworld.cpp

clean:
	rm a *.o