//Pat Wongwiset
//nw9ca
//11/17/17
//heap.h

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include "heapNode.h"
#include <unordered_map>

using namespace std;

class heap{
 public:
    heap();
    ~heap();
    heap(vector<heapNode*> vec);
    void insert(int x, char cc);
    void insert(heapNode*& hN);
    heapNode* const findMin();
    heapNode* const deleteMin();
    void makeTree();
    void readPrefix(heapNode*& root, string prefix);
    void print();
    unordered_map<string, string> getMap();
    vector<heapNode*> heapVec;
    unordered_map<string, string> mymap;

 private:
    unsigned int size;
    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
 
  
