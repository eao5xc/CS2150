//Pat Wongwiset
//nw9ca
//hashTable.h
//10/11/17

//need improvement! - hashFn
//want more info - substring (prefix) 


#include <iostream>
#include <stdio.h>
#include <string.h>
#include "hashTable.h"
#include <string>
#include <math.h>

using namespace std;
#define MOD 1000000007


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

int power(int base, int power){
  int result = 1;
  while(power > 0){
    if(power % 2 == 1){
      result = (result*base) % MOD;
    }
    base = (base*base)% MOD;
    power = power/2;
  }
  return result;
}


hashTable::hashTable(){ // constructor
  size = 1000;
  hTable[size];
}

//hashTable::~hashTable(){
// delete [] hTable;
// }

hashTable::hashTable(int sizeDict){ //one-param constructor
  size= getNextPrime(sizeDict*2);
  hTable[size];
  
}

int hashTable::hashFunct(string s){ //hash_function
  int prime = 37;
  int i = 0;
  int k = 0;
  
  
  while(i != s.length()-1){
    //k+= s[i]*power(prime,i);//<-need to fix  here (want it to be faster)
    k += s[i];
    i++;
  }

  return fmod(k, size);
  
    
}

  
  

void hashTable::insert(string s){ //hash: inserting
  int key = hashFunct(s);

  /*
  while(hTable[key] != "" && hTable[key] != s){
  key++;
  }
  if(key < size){
  hTable[key] = s;
  }
  if(key >= size){
    key = key % size;
    while(hTable[key] != "" && hTable[key] != s){
      key++;
    }
    hTable[key] = s;
  }
  */
  while(hTable[key] != "" && hTable[key] != s){
    key++;
    key = key % size;
  }

  hTable[key] = s;
  
}

string hashTable:: find(string s){
  int hashNum = hashFunct(s);
  while(hTable[hashNum] != "" && hashNum <  size){
    if(hTable[hashNum] != s){
      hashNum++;
    }
    if(hTable[hashNum] == ""){
      return "";
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
//./a.out words.txt 4x7.grid.txt

      



  
    
  
