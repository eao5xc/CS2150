//Pat Wongwiset
//nw9ca
//hashTable.h
//10/11/17


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "hashTable.h"
#include <string>
#include <math.h>

#define MOD 1000000007

using namespace std;


bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}


hashTable::hashTable(){ // constructor
  size = 1000;
  hTable.reserve(size);
}

//hashTable::~hashTable(){
// delete [] hTable;
// }

hashTable::hashTable(int sizeDict){ //one-param constructor
  size= getNextPrime(sizeDict*2);
  hTable.reserve(size);
  
}

unsigned int boostPower(int base, int power){
  unsigned int result = 1;
  while( power > 0){
    if(power % 2 == 1){
      result = (result*base)% MOD;
    }
    base = (base*base) % MOD;
    power = power/2;
  }

  return result;
}

int hashTable::hashFunct(string s){ //hash_function

  int i = 0;
  unsigned int k = 0;
  int prime =101;
  
  
  while(i <= s.length()-1){
    // k+=s[i]* boostPower(prime,i);
    k+= s[i]*prime;
    
    i++;
  }

  return k % size;
  
  
    
}



int hashTable::hashFunct2(string s){ //hash_function

  int i = 0;
  unsigned int k = 0;
  
  
  while(i <= s.length()-1){
    k+= s[i];
    
    i++;
  }

  return size - (k % size);
  
  
    
}

  


void hashTable::insert(string s){ //hash: inserting
  unsigned int key = hashFunct(s);
  //int offset = hashFunct2(s);
  int i = 0;
  while(hTable[key] != "" && hTable[key] != s){
    //key ++; //2nd code
    i++;
    key = (key + i*i) % size; //quadratic
    // key = (key + i*offset) % size;
  }

  hTable[key] = s;
  
}

string hashTable:: find(string s){
  unsigned int hashNum = hashFunct(s);
  //int offset = hashFunct2(s);
  int i = 0;
  while(hTable[hashNum] != ""){
    if(hTable[hashNum] != s){
      hashNum = (hashNum + i*i) % size;//quadratic
      i++;
      //hashNum++; //2nd code
      //hashNum = (hashNum + i*offset) % size;
    }
    if(hTable[hashNum] == s){
      return s;
    }
  }
  return "";
}

int hashTable::getSize(){
  return size;
}

//cd Documents/pdr/labs/lab06/code
//make
//./a.out words2.txt 300x300.grid.txt

      



  
    
  
