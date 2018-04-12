//Pat Wongwiset
//nw9ca@virginia.eud
//09/11/17
//Stack.h

/*
 * Filename: Stack.h
 * 
 */
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "StackNode.h"

using namespace std;



class Stack {
public:
  Stack(); //constructor
  ~Stack(); //destructor
  bool isEmpty() const; //checks whether the stack is empty
  void push(int value); //push value to stack
  void pop(); //pop top out of stack
  int top() const; //return top of stack
  int size() const; //return size
    

 private:
  StackNode *head, *tail;	//indicates beginning of stack
  int count;
  
    friend class StackNode;
    friend class postfixCalculator;
};


#endif
/* end of Stack.h */
