//Pat Wongwiset
//nw9ca
//hashTable.h
//10/11/17

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class hashTable {
 private:
   int size;
  string  hTable[1];
  
 public:
  hashTable(); //constructor
  hashTable(int sizeDict);
  //~hashTable();
  string find(string s);
  int hashFunct(string s);
  void insert(string st);
  // void rehash();
  int getSize();
};

bool checkprime(unsigned int p);
int getNextPrime(unsigned int n);
int power(int base, int power);


#endif
