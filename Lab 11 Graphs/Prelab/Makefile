#Niphattha (Pat) Wongwiset
#nw9ca@virginia.edu
#Makefile
#11/26/17

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 -g -std=c++11
OFILES= middleearth.o topological.o
.SUFFIXES: .o .cpp
#all:	doxygen a.out
a.out: topological.o 
	$(CXX) topological.o
	doxygen
#doxygen: doxygen
#	doxygen
clean:
	-rm -f *.o *~

