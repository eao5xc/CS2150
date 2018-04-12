//Pat Wongwiset
//nw9ca
//11/17/17
//heapNode.cpp


#include <iostream>
using namespace std;
#include "heapNode.h"


heapNode::heapNode(){
  f = 0;
  c = ' ';
  left = NULL;
  right = NULL;
}

heapNode::heapNode(int ff, char cc){
  f = ff;
  c = cc;
  left = NULL;
  right = NULL;
  
}

int heapNode::getFrequency(){
  return f;
}

char heapNode::getChar(){
  return c;
}

heapNode*& heapNode::getLeft(){
  return left;
}

heapNode*& heapNode::getRight(){
  return right;
}




