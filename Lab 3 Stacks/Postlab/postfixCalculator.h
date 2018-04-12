//Pat Wongwiset
//nw9ca
//09/11/17
//PostfixCalculator.h

#ifndef POSTFIXCAL_H
#define POSTFIXCAL_H

#include <iostream>
#include <cstdlib>
//#include <stack>
#include "Stack.h"
#include "StackNode.h"

using namespace std;

class PostfixCalculator{
 public:
  PostfixCalculator(); //Constructor
  
  PostfixCalculator(int x); // One Parameter Constructor

  //  ~PostfixCalculator(); //Destructor

  //PostfixCalculator(const PostfixCalculator& source); //Copy Constructor

  //PostfixCalculator& operator = (const PostfixCalculator& source); //Equals Operator
  
  void push(int x);   //add an integer to a stack

  int top ();  //return the element on the top of the stack. It does not remove that element from the top and will return error message when the stack is empty

  void pop(); // remove the element on the top of the stack, but does not return it. If the stack is empty, then somehow an error must be indicated

  bool empty(); //tell whether there are any elements left in the stack (false) or not (true)

  void add(); //add 2 values from the last pushed integers together, remove both, and  add the result to stack.

  void subtract(); //remove  2 values from the last pushed integers together, remove both from the stack, and  add the result to stack, return the result
  //The result = (the second popped) - (the first popped)

  void multiply(); //multiply  2 values from the last pushed integers together, remove both from the stack, and  add the result to stack

   void divide(); //use 2 values from the last pushed integers together, remove both from the stack, and  add the result to stack
  //The result = (the second popped /(the first popped)

   void negate(); //negate at the top of stack

   int getToValue(); // return result value

 private:
   Stack stk; //hold numbers to the stack
   friend class Stack;

};

#endif

/* end of postfixCalculator.h */

  
  
