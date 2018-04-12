//Pat Wongwiset
//nw9ca
//09/09/17
//postfixCalculator.cpp

#include "postfixCalculator.h"

using namespace std;

PostfixCalculator::PostfixCalculator(){ //Default Constructor
}

PostfixCalculator::PostfixCalculator(int x){ //One parameter Constructor
  stk.push(x);
}

//PostfixCalculator::~PostfixCalculator(){ //Destructor
//while(!stk.empty()){
//  stk.pop();
//}
  
//}

//PostfixCalculator::PostfixCalculator(const PostfixCalculator& source){ //Copy Constructor
//stack<int> stk;
//stack<int> stk_old = source.stk;
//while(!stk_old.empty()){
// int x = stk_old.top();
// stk.push(x);
// stk_old.pop();
//}
//}

//PostfixCalculator& PostfixCalculator:: operator=(const PostfixCalculator& source){ //Equals operator
//if(this == &source){
// return *this;
// }
//else{
// stack<int> old_stk = source.stk;
//while(!old_stk.empty()){
//  int x = old_stk.top();
//  stk.push(x);
//  old_stk.pop();
// }
//}
//}

void PostfixCalculator:: push(int x) { //push(): add element at the top
    stk.push(x);
}

int PostfixCalculator::top(){ //top(): return top element
  return stk.top();
}

bool PostfixCalculator:: empty(){ //tell whether there are any elements left in the stack
  return stk.isEmpty();
}

void PostfixCalculator:: add(){ //addition
  int x = stk.top();
  stk.pop();
  int y = stk.top();
  stk.pop();
  stk.push(x+y);
}

void PostfixCalculator:: subtract(){ //subtraction
  int x = stk.top();
  stk.pop();
  int y = stk.top();
  stk.pop();
  stk.push(y-x);
}

void PostfixCalculator:: multiply(){ //multiplication
  int x = stk.top();
  stk.pop();
  int y = stk.top();
  stk.pop();
  stk.push(y*x);
}

void PostfixCalculator:: divide(){ //division
  int x = stk.top();
  stk.pop();
  int y = stk.top();
  stk.pop();
  stk.push(y/x);
}

void PostfixCalculator:: negate(){ //negation
  int x = stk.top();
  stk.pop();
  stk.push(x*(-1));
}

int PostfixCalculator:: getToValue(){ //return result of the operation
  while(stk.size() != 1){
    stk.pop();
  }
  return stk.top();
    
}





    




  
				   
