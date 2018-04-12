//Pat Wongwiset
//nw9ca
//11/17/17
//heap.cpp

#include <iostream>
#include "heap.h"
#include "heapNode.h"
using namespace std;
//constructor
heap::heap(){
  heapNode* hN = new heapNode();
  heapVec.push_back(hN);
  size = 0;
}

//one param constructor (from unsorted vector)
heap::heap(vector<heapNode*> vec) : size(vec.size()){
  heapVec = vec;
  heapVec.push_back(heapVec[0]);
  heapNode* hN = new heapNode();
  heapVec[0] = hN;
  for(int i = size/2; i > 0; i --)
    percolateDown(i);
}


//destructor
heap::~heap(){
}

void heap::insert(int x,char cc){
  heapNode* hN = new heapNode(x, cc);
  heapVec.push_back(hN);
  percolateUp(++size);
}

void heap::insert(heapNode*& hN){
  heapVec.push_back(hN);
  percolateUp(++size);
}

void heap::percolateUp(int hole){
  heapNode* temp = heapVec[hole];
  int x = heapVec[hole]->f;
  for( ;(hole> 1) && (x < heapVec[hole/2]->f) ; hole /= 2){
      heapVec[hole] = heapVec[hole/2];
  }
  heapVec[hole] = temp;
}

heapNode* const  heap::deleteMin(){ 
  if(size == 0){
    // throw "Empty heap";
    return NULL;
  }
  heapNode* ret = heapVec[1];
  //  cout << ret->f << ": " << ret->c <<endl;
  heapVec[1] = heapVec[size--];
  heapVec.pop_back();
  percolateDown(1);
  return ret;
}

void heap::percolateDown(int hole){
  heapNode* temp =heapVec[hole];
  int x = heapVec[hole]->f;
  while(hole*2 <= size){
    int child = hole*2; //left child
      if((child + 1 <= size) && (heapVec[child+1]->f < heapVec[child]->f)){
	child++;
      }
      if(x > heapVec[child]->f){
      heapVec[hole] = heapVec[child];
      hole = child;
    }
    else
      break;
  }

  heapVec[hole] = temp;
}
  
heapNode* const  heap::findMin() {
  if ( size == 0 ){
        throw "findMin() called on empty heap";
  }
  //  cout << heapVec[1].c << ":" << heapVec[1].f << endl;
    return heapVec[1];
}

//make HuffTree
void heap::makeTree(){
  while(this->size !=1){
  heapNode* root = new heapNode();
  heapNode* newLeft = this->deleteMin();
  heapNode* newRight = this->deleteMin();
  root->f = newLeft->getFrequency() + newRight->getFrequency();
   if(newLeft->getFrequency() == newRight->getFrequency()){
    heapNode* temp = newRight;
    heapNode* temp2 = newLeft;
  if((newRight->right != NULL) && (newLeft->right == NULL)){
    newLeft = temp;
    newRight = temp2;
  }
   }
  root->left = newLeft;
  root->right = newRight;
  this->insert(root);
  }
}

//find prefix (think about how to return)

void  heap::readPrefix(heapNode*& root, string prefix){
  if((root->left == NULL)&&(root->right == NULL)){
    string str = string(1,root->c);
    if(str == " "){
      str = "space";
    }
    cout << str <<  " " << prefix << endl;
    mymap[str] = prefix;
    
  }
  else{
    readPrefix(root->left, prefix + "0" );
    readPrefix(root->right, prefix + "1");
  }
}


void heap::print(){
      for ( int i = 1; i <= this->size; i++ ) {
        cout << this->heapVec[i]->c << " " << this-> heapVec[i]->f << endl;;
      }
}

unordered_map<string, string> heap::getMap(){
  return mymap;
}



