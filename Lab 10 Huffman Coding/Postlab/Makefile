#Niphattha (Pat) Wongwiset
#nw9ca@virginia.edu
#Makefile
#11/21/17

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 -g -std=c++11
OFILES= heapNode.o heap.o
.SUFFIXES: .o .cpp
all:	encoder decoder
encoder: huffmanenc.o $(OFILES)
	$(CXX) $(OFILES) huffmanenc.o -o encoder
decoder: huffmandec.o $(OFILES)
	$(CXX) $(OFILES) huffmandec.o -o decoder
clean:
	-rm -f *.o *~

