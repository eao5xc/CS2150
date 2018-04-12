//Niphattha (Pat) Wongwiset
//nw9ca@virginia.edu
//09/16/17
//prelab4.cpp

#ifndef PRELAB4
#define PRELAB4

#include <iostream>
#include <string>
#include <climits>
#include <typeinfo>

using namespace std;


union Data{
  int i;
  float f;
  unsigned int ui;
  double d;
  char c;
  bool b;
  int* iPtr;
  char* cPtr;
  double* dPtr;
};

class PreLab4{
public:
PreLab4(); //Constructor
  PreLab4(union Data x); // one constructor
  // ~PreLab4();
  void sizeOfTest(); //sizeOfTest: return size of test of integer
  void overflow(); //overflow

private:
  union Data data;
};

void outputBinary(unsigned int i);

#endif

PreLab4::PreLab4(){
  data.i = 0;
}

//PreLab4 ::~PreLab4(){
// delete data;
//}

PreLab4::PreLab4(union Data d){
  data = d;
}


void PreLab4:: sizeOfTest(){ //sizeOfTest: finding the bytes that is used for different type
   cout << "Size of int " << "is " << sizeof(data.i) << endl;
  cout << "Size of float " << "is " << sizeof(data.f) << endl;
  cout << "Size of unsigned int " << "is " << sizeof(data.ui) << endl;
  cout << "Size of double " << "is " << sizeof(data.d) << endl;
  cout << "Size of char " << "is " << sizeof(data.c) << endl;
  cout << "Size of bool " << "is " << sizeof(data.b) << endl;
  cout << "Size of int* " << "is " << sizeof(data.iPtr) << endl;
  cout << "Size of char* " << "is " << sizeof(data.cPtr) << endl;
  cout << "Size of " << typeid(data).name() << " is " << sizeof(this) << endl;

}

void outputBinary(unsigned int i){ //outputBinary(): convert integer to 32-bit binary representation
  int val = i;
  char b[] = "0000 0000 0000 0000 0000 0000 0000 0000";
  //string b;
  int j = 38;
    while(j >= 0 ){
    if( (j% 5) == 4 && j != 38){
      j = j -1;
    }
    else{ 
    if( (i%2) == 1){
      b[j] = '1';
      
    }
    i /= 2;
     j = j -1;
    }
      
  }
    cout << "Number: " << val << " binary: " << b << endl;
}

void PreLab4::overflow(){
  unsigned int x = UINT_MAX;
  cout << "UINT_MAX is " << x << endl;
  x++;
  cout << "UINT_MAX + 1  = " << x << endl;
  
}

int main(){

  int x;
  cout << "Enter A Number: " << endl;
  cin >> x;
  union Data d;
  d.i = x;
  PreLab4 p4(d);
  cout << "____________sizeOfTest()__________" << endl;
  p4.sizeOfTest();
  cout << "____________outputBinary()_________" << endl;
  outputBinary(x);
  cout << "____________overflow()_____________" << endl;
  p4.overflow();
  cout << "Q1: What happens when you add 1 to an unsigned int variable containing the maximum value of an unsigned int?" << endl;
  cout << "Ans1: the result is 0" << endl;
  cout << "Q2: Does the program halt?" << endl;
  cout << "Ans2: No, it does not" << endl;
  cout << "Q3: What answer do you get?" << endl;
  cout << "Ans3: 0" << endl;
  cout << "Q4:Why does this happen?" << endl;
  cout << "Ans4: Because the bit representation (memory address) of the unsigned integer is overflow. When all bits position  are 1 and then adding 1 into it, all bits turn to 0 causing result to be 0." << endl;
 
  
  return 0;
}



