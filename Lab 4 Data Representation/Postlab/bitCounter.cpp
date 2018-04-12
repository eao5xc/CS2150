//Pat Wongwiset
//nw9ca@virginia.edu
//bitCounter.cpp
//09/20/17

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int bitCounter(int x){
  if(x%2 == 0 && x != 0){
    return bitCounter(x/2);
  }
    if(x %2 != 0){
  return 1 + bitCounter(x/2);
  }
  return 0;
  }
    


int main (int argc, char **argv){
  if(argv[1] == NULL){
    cout << "Please put a command-line parameter" << endl;
    exit(EXIT_FAILURE);
  }
  int x = stoi(argv[1]);
  cout << "The number of 1 in binary form is " << bitCounter(x) << endl;
  
}
