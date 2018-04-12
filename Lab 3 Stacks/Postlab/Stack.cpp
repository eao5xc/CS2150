//Pat Wongwiset
//nw9ca@virginia.edu
//09/11/17
//List.cpp

#include "Stack.h"
#include "StackNode.h"
#include <iostream>
#include <string>
using namespace std;



Stack::Stack(){                        //Default Constructor
  head = new StackNode;
  tail = new StackNode;
  head->next = tail;
  tail->previous = head;
  count = 0;
}

Stack::~Stack(){                      //Destructor
  while( head->next != tail){
    pop();
  }
  delete head;
  delete tail;
    
}


bool Stack:: isEmpty() const{         //isEmpty(): return true if the stackis empty
  if(head->next == tail){
    return true;
  }
  return false;
}


void Stack::push(int x){ //push(): add element at top
    StackNode* temp = new StackNode;
  temp->value = x;
  temp->previous = tail->previous;
  tail->previous->next = temp;
  temp->next = tail;
  tail->previous = temp;
  count ++;
}


int Stack::top() const{ //top(): return top of stack
  return tail->previous->value;
}

  void Stack::pop(){      //pop(): remove element at top of the stack

    StackNode* temp;
  temp = tail->previous;
  tail->previous->previous->next = tail;
  tail->previous = tail->previous->previous;
  delete temp;
  count --;
}

int Stack::size() const{ //size()
  return count;
}




