//Pat Wongwiset 
//nw9ca@virginia.edu
//xToN.cdd
//8/27/17

#include <iostream>
using namespace std;

int xton(int a, int b){
  if(b == 0){
    return 1;
  }
  return a* xton(a,b-1);
}

int main(){
  int a, b, c;
  cout << "Enter the first number:" << endl;
  cin >> a;
  cout << "Enter the exponent:" << endl;
  cin >> b;
  c = xton(a, b);
  cout  << a << "^" << b<< " ) is " <<  c << endl;
  return 0;
}

