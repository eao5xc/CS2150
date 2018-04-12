//Pat Wongwiset
//nw9ca@virginia.eud
//09/11/17
//StackNode.h


#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class StackNode {
public:
    StackNode();                 // Constructor

private:
    int value;
    StackNode *next,*previous;	// for doubly linked lists

    //stack needs to be able to access/change StackNode's next and
    // previous pointers
    friend class Stack;
    friend class postfixCalculator;

   

    // Not writing a destructor is fine in this case since there is no
    // dynamically allocated memory in this class.  No constructor is
    // necessary, as an object will be set up by the List class.
};

#endif
