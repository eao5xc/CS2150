#Niphattha (Pat) Wongwiset
#nw9ca@virginia.edu
#Makefile
#10/13/17

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 -g -std=c++11
OFILES= wordPuzzle.o timer.o hashTable.o
.SUFFIXES: .o .cpp
wordPuzzle: $(OFILES)
	$(CXX) $(OFILES)
clean:
	-rm -f *.o *~

