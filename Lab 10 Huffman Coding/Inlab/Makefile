#Niphattha (Pat) Wongwiset
#nw9ca@virginia.edu
#Makefile
#11/19/17

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 -g -std=c++11
#OFILES= huffmandec.o heapNode.o
OFILES= huffmandec.o heapNode.o
.SUFFIXES: .o .cpp
wordPuzzle: $(OFILES)
	$(CXX) $(OFILES)
clean:
	-rm -f *.o *~

