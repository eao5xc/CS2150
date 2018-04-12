//Pat Wongwiset
//nw9ca
//11/17/17
//heapNode.h

#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <iostream>
using namespace std;


class heapNode{
public:
  heapNode();
  heapNode(int ff, char cc);
  int getFrequency();
  char getChar();
  heapNode*& getLeft();
  heapNode*& getRight();
  
  
 private:
  int f;
  char c;
heapNode *left,*right;
//  friend class heap;
};

#endif
