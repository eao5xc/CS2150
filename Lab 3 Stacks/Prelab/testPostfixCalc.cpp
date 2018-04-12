//Pat Wongwiset
//nw9ca
//09/12/17
//postfixCalculator.cpp

#include "postfixCalculator.h"
#include <string>
#include <iostream>
#include <cstdlib>


using namespace std;

int main(){
   PostfixCalculator p;
   cout << "create postfixCalculator called p" << endl ;

   cout << "__________check addition_______" << endl;
  p.push(2);
  cout << "Enter: " << p.top() << endl;
  p.push(3);
  cout << "Enter: " << p.top() << endl;
  p.add();
  cout << "2 + 3 = " << p.top() << endl;

  cout << " ___________check subtraction_______" <<endl;
  p.push(2);
  cout << "Enter: " << p.top() << endl;
  p.push(3);
  cout << "Enter: " << p.top() << endl;
  p.subtract();
  cout << "2 - 3 = " << p.top() << endl;

   cout << " ___________check multiplication_______" <<endl;
  p.push(20);
  cout << "Enter: " << p.top() << endl;

  p.push(30);
  cout << "Enter: " << p.top() << endl;
  p.multiply();
  cout << "20* 30 = " << p.top() << endl;

  cout << " ___________check division_______" <<endl;
  p.push(60);
  cout << "Enter: " << p.top() << endl;
  p.push(30);
  cout << "Enter: " << p.top() << endl;
  p.divide();
  cout << "60/ 30 = " << p.top() << endl;

  cout << " ___________check unary negation_______" <<endl;
  p.push(20);
  cout << "Enter: " << p.top() << endl;
  p.push(30);
  cout << "Enter: " << p.top() << endl;
  p.negate();
  cout << "~30 = " << p.top() << endl;

  cout << "____empty______" <<endl;
  cout << "check p is empty? (0 means that the calculator is not empty): " << p.empty() << endl;

  

  cout << "(IN-LAB)_____postfix notation______" <<endl;


  //in-lab part
  
  PostfixCalculator c;

  string s;

  //how to create negative number? (here is the answer)
  //atoi would convert integer even it's negative-> create additional condition to add negative number
  //order of condition matters (short circuit), so we have to check size() then check character in s
  // 0 equals false
  
   while (cin >> s) {
    const char* arr_char = s.c_str();
    if(isdigit(arr_char[0]) != 0){
      	int x = atoi(arr_char);
	c.push(x);
	//	cout << "Enter: " <<  c.top() << endl;
      }
    if(s.size() > 1 && isdigit(arr_char[1]) && arr_char[0] == '-'){
      	int x = atoi(arr_char);
	c.push(x);
	//cout << "Enter: " <<  c.top() << endl;
    }
    else if(s == "+"){
    	  c.add();
	  //cout << "Result: " << c.top() << endl;
    	}
    else if(s == "-"){
	c.subtract();
	//cout << "Result: " << c.top() << endl;
      
     }
    else if(s == "*"){
	c.multiply();
	//cout << "Result: " << c.top() << endl;
     }
    else if(s == "/"){
	c.divide();
	//cout << "Result: " << c.top() << endl;
     }
    else if(s == "~"){
	c.negate();
	//cout << "Result: " << c.top() << endl;
     }
    }
   cout << "Result: " << c.getToValue() << endl;
   
    return 0;
  

  
}

