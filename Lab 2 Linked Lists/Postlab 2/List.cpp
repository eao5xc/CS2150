//Pat Wongwiset
//nw9ca@virginia.edu
//09/03/17
//List.cpp

#include "List.h"
#include "ListItr.h"
#include <iostream>
#include <string>
using namespace std;

List::List(){                        //Default Constructor
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  tail->previous = head;
  count = 0;
}

List::~List(){                      //Destructor
  makeEmpty();
  delete head;
  delete tail;

    
}

List::List(const List& source) {      // Copy Constructor
  head=new ListNode;
  tail=new ListNode;
  head->next =tail;
  tail->previous =head;
  count=0;
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {       // deep copy of the list
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

List& List::operator=(const List& source) { //Equals operator
  if (this == &source)
    return *this;
  else {
    makeEmpty();
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

bool List:: isEmpty() const{         //isEmpty(): return true if the list is empty
  if(head->next == tail && tail->previous == head){
    return true;
  }
  return false;
}


void List:: makeEmpty(){        //makeEmpty(): removes/reclaims all items from a list, except the dummy head and tail nodes.
  ListItr cur;
  cur.current = tail->previous;
  while(cur.current != head){
    cur.moveBackward();
    delete (cur.current)->next;
  }
  head->next = tail;
  tail->previous = head;
  count = 0;
}

ListItr List:: first(){      //first(): returns an iterator that points to the ListNode in the first position
  ListItr temp;
  temp.current = head->next;
  return temp;
}

ListItr List:: last(){     //last():returns an iterator that points to the ListNode in the last position
  ListItr temp;
  temp.current = tail->previous;
  return temp;
}

void List:: insertAfter(int x, ListItr position) //insertAfter: inserts x after the current iterator position
{
  ListNode* temp = new ListNode;
  temp->value = x;
  temp->next = (position.current)->next;
  (position.current)->next->previous =temp;
  temp->previous = position.current;
  (position.current)->next = temp;

  count += 1;
} 

  void List:: insertBefore(int x, ListItr position){//insertBefore:  inserts x before the current iterator position
      ListNode* temp = new ListNode();
      temp->value = x;
    temp->previous = (position.current)->previous;
 (position.current)->previous->next =temp;
  temp->next = (position.current);
   (position.current)->previous = temp;
      count += 1;
}

  void List::insertAtTail(int x){ //insertAtTail
  ListNode* temp = new ListNode;
  temp->value = x;
  temp->previous = tail->previous;
  tail->previous->next = temp;
  temp->next = tail;
  tail->previous = temp;
  count += 1;
  
}

  void List::remove(int x){      //remove

    ListNode* temp;
  temp = head->next;
  while(temp->value != x && temp != tail){
    ListNode* new_temp = temp->next;
    temp = new_temp;
  }
  if(temp->value == x && temp != tail){
    ListNode* new_temp = temp->next;
    ListNode* pre_temp = temp-> previous;
    delete temp;
    count -= 1;
    new_temp->previous = pre_temp;
    pre_temp-> next = new_temp;
  }
}

 ListItr List::find(int x){   //find
  ListNode*  temp = head->next;
  ListItr  cur;
  while(temp->value != x && temp != tail){
    ListNode* new_temp  = temp->next;
    temp = new_temp;
  }
  if(temp->value == x){
    cur.current = temp;
    return cur;
  }
  cur.current = tail;
  return cur ;
}

int List::size() const{             //size
  return count;

}

void printList(List& source, bool direction){  //printList
  ListItr temp;
  if(direction){
    temp = source.first();
    while(!temp.isPastEnd()){
      cout << temp.retrieve() << endl;
      temp.moveForward();
    }
  }
  else{
    
    temp = source.last();
     while(!temp.isPastBeginning()){
       cout << temp.retrieve() << endl;
	temp.moveBackward();
      }
    
  }
}

