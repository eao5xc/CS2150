//Pat Wongwiset
//nw9ca
//11/17/17
//huffmanenc.cpp

//clang++ -Wall -g  heapNode.cpp heap.cpp huffmanenc.cpp
//./a.out normal1.txt

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include "heap.h"

using namespace std;

int main(int argc, char **argv){
  if ( argc != 2 ) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }
  FILE *fp = fopen(argv[1], "r"); //open the file in read mode

  //check if the file exists
  if ( fp == NULL ) {     
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
  }
 char g;
 vector<int> freq;
 vector<char> ch;
 int length = 0;
 //create two vector to collect frequency of character and character (Both order will have the same index to retrieve value correctly)
 while ( (g = fgetc(fp)) != EOF ){
   //in case that g already existed in the vector
   if(find(ch.begin(),ch.end(),g) != ch.end()){
     int pos = find(ch.begin(),ch.end(),g) - ch.begin();
     freq[pos] += 1;
     length++;
   }
     //if not, pushing back g to it
     else if( (g >= 0x20)&& (g<= 0x7e)){  
     ch.push_back(g);
     freq.push_back(1);
     length++;
     }
 }

 heap* h = new heap();

 int i = 0;
while(i < freq.size()){
  h->insert(freq[i], ch[i]);
  i++;
}

 heap* oldHeap = h;
h->makeTree();

 h->readPrefix(oldHeap->heapVec[1], "");
 unordered_map<string, string> lib = h->getMap();
 unordered_map<string,string>::iterator it;
 
 cout <<"----------------------------------------" << endl;
 
rewind(fp);
 string encoded = "";
 while ( (g = fgetc(fp)) != EOF ){
   string str = string(1,g);
   if(g == ' '){
     str = "space";
   }
   it = lib.find(str);
   if(it != lib.end()){
   cout << it->second << " ";
   encoded += it->second;
   }
 }
 cout << endl; 
   fclose(fp);
   
  cout <<"----------------------------------------" << endl;

  double lengthEncoded = encoded.length();
  double cmpRatio = length*8/lengthEncoded;
  double costHuff = lengthEncoded/length;

  cout <<"There are a total of " << length << " symbols that are encoded." << endl;
  cout <<"There are " << freq.size() << " distinct symbols used." << endl;
  cout <<"There were " << length*8 << " bits in the original file." << endl;
  cout <<"There were " << lengthEncoded << " in the compressed file." << endl;
  cout <<"This gives a compression ratio of " << cmpRatio << "." << endl;
  cout <<"The cost of the Huffman tree is " <<  costHuff << " bits per character." << endl;
   
 
  return 0;
}
