#Niphattha (Pat) Wongwiset
#nw9ca@virginia.edu
#Makefile
#11/28/17

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 -g -std=c++11
OFILES= middleearth.o traveling.o
.SUFFIXES: .o .cpp
#all:	doxygen a.out
a.out: $(OFILES)
	$(CXX) $(OFILES)
	doxygen
#doxygen: doxygen
#	doxygen
clean:
	-rm -f *.o *~

