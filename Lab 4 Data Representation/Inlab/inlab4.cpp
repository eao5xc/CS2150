//Niphattha (Pat) Wongwiset
//nw9ca@virginia.edu
//09/19/17
//inlab4.cpp

#include <iostream>
#include <climits>
#include <cfloat>
#include <stdint.h>
using namespace std;

int main(){
  cout << "_____________worksheet________" << endl;
  //check max value
  cout << "int max " << INT_MAX << endl;
  cout << "unsign int max " << UINT_MAX << endl;
    cout << "float max " << FLT_MAX << endl;
   cout << "double max " << DBL_MAX << endl;
 cout << "char max " << CHAR_MAX << endl;
 
 //check how 0 is stored in the program (hex)
 int A = 0;
 unsigned int AA = 0;
 float AAA = 0;
 double AAAA = 0;
 char AAAAA = '0';
 bool AAAAAA = false;
 
 //check how 1 is stored in the program (hex)
  int B = 1;
 unsigned int BB = 1;
 float BBB = 1;
 double BBBB = 1;
 char BBBBB = '1';
 bool BBBBBB = true;
 
 //check ptr
 int* X = NULL;
 char* XX = NULL;
 double* XXX = NULL;

 int Y = INTPTR_MAX;

 cout << "____________________" << endl;
 
  cout << "__________Representation in Memory_________" << endl;
  bool b = true;
  char c = 'a';
  int i = 1;
  double d = 1.1;
  int* j = &i;

  cout << "boolean: " << b << endl;
  cout << "character: " << c << endl;
  cout << "integer: " << i << endl;
  cout << "double: " << d << endl;
  cout << "int*: " << j << endl;

  cout << "______________________" << endl;

  cout << "Primitive arrays in C++" << endl;

  int IntArray[10] = { 0,1,2,3,4,5,6,7,8,9};
  char CharArray[10]={'a','b','c','d','e','f','g','h','i','j'};

 int IntArray2D[6][5];
char CharArray2D[6][5];

 int ii;
 int jj;
 int kk = 10;
 char xx = 'z';
 for( ii = 0; ii < 6; ii++){
   for(jj = 0; jj< 5; jj++){
     IntArray2D[ii][jj] = kk;
     CharArray2D[ii][jj] = xx;
     kk++;
     xx = xx + 'z';
       }
 }

 cout << "Address of IntArray[0] is " << &(IntArray[0]) << endl;
 //cout << "Address of CharArray[0] is " << &(CharArray[0]) << endl;
 cout << "Address of IntArray2D[0][0] is " << &(IntArray2D[0][0]) << endl;
 //cout << "Address of CharArray2D[0][0] is " << &(CharArray2D[0][0])<< endl;
 
 cout <<"_____________________________________"<< endl;
 
 cout << "Base address of IntArray2D " <<  &(IntArray2D) << endl;
 cout << "&(IntArray2D[0][0]) is " <<  &(IntArray2D[0][0])  << endl;
 cout << "&(IntArray2D[4][3]) is " <<  &(IntArray2D[4][3])  << endl;
 cout << "&(IntArray2D[4][4]) is " <<  &(IntArray2D[4][4])  << endl;
 cout << "&(IntArray2D[5][3]) is " <<  &(IntArray2D[5][3])  << endl;
 cout << "&(IntArray2D[5][4]) is " <<  &(IntArray2D[5][4])  << endl;
 cout << "&(IntArray2D[5][0]) is " <<  &(IntArray2D[5][0])  << endl;

 

  return 0;
}
