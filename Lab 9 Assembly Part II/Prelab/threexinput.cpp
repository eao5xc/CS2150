//Pat Wongwiset
//nw9ca
//11/8/17
//threexinput.cpp

#include <iostream>
#include "timer.h"
#include <cstdlib>

using namespace std;

extern "C" long threexplusone (long);

int main() {
  int num, step;
  int n;

  cout << "Please enter the input number";
  cin >> num;

  cout << "Please enter the number of times to call subroutine";
  cin >> n;

  timer totalTime;
  totalTime.start();
  for(int i = 0; i < n; i++){;
    step = threexplusone(num);
  }
  totalTime.stop();

  cout << "The average time:" << totalTime.getTime()*1000/n << "ms." << endl;
  cout << "The total step: " << step << endl; 

  return 0;

}

