//Pat Wongwiset
//nw9ca@virginia.edu
//09/03/17
//ListItr.cpp

#include "ListItr.h"



ListItr::ListItr(){			//Constructor
  current = NULL;
}

ListItr::ListItr(ListNode* theNode){   // One parameter constructor
  current = theNode;
}

bool ListItr:: isPastEnd() const {               //isPastEnd
  if(current->next == NULL){
    return true;
  }
  
  return false;
}

bool ListItr:: isPastBeginning()const {       //isPastBeginning
  if(current->previous == NULL){
    return true;
}
  return false;
}

void ListItr:: moveForward(){                //moveForward
  if(current->next != NULL){
    ListNode* temp;
    temp = current->next;
    current = temp;
  }
}

void ListItr:: moveBackward(){             //moveBackward
  if(current->previous != NULL){
    ListNode* temp;
    temp = current->previous;
    current = temp;
  }
}

int ListItr:: retrieve() const{          //retrieve
  return current->value;
}


  



