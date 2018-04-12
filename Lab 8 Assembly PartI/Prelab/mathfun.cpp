// main.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);

int  main () {

    // delcare the local variables
  int  num1, num2, productRet, powerRet;

    // how big is the array we want to use?
    cout << "Please enter the first number:  ";
    cin >> num1;

    cout << "Please enter the second number:  ";
    cin >> num2;

   // multiply 2 numbers  and print out results
    productRet = product(num1, num2);
    cout << "The product of 2 numbers are  " << productRet << endl;

   // Find result of powering between 2 numbers
    //assuming 1st param is a base and 2nd param is a power number
    //and then print out results
    powerRet = power(num1, num2);
    cout << "The power("<< num1 << " , " << num2  <<  ") are  " << powerRet << endl;

    // all done!
    return 0;
}
