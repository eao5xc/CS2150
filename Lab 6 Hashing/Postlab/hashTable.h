//Pat Wongwiset
//nw9ca
//hashTable.h
//10/11/17

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class hashTable {
 private:
   int size;
  vector<string>  hTable;
  
 public:
  hashTable(); //constructor
  hashTable(int sizeDict);  //one-param constructor
  //~hashTable();
  string find(string s);
  int hashFunct(string s);
  int hashFunct2(string s);
  void insert(string st);
  int getSize();
};

bool checkprime(unsigned int p);
int getNextPrime(unsigned int n);
unsigned int boostPower(int base, int power);


#endif
