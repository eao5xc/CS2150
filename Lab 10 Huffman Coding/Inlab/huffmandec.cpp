//Pat Wongwiset
//nw9ca
//11/20/17
//huffmandec.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "heapNode.h"
using namespace std;

void decTree(heapNode*& root,char in, string prefix,int i ){
  if(i == prefix.length()){
    root = new heapNode(0, in);
    // cout << root->getChar() << endl;
  }
  else{
    if(root == NULL){
      root = new heapNode();
    }
    if(prefix[i] ==  '0'){
      decTree(root->getLeft(), in, prefix, i+1);
    }
    if(prefix[i] == '1'){
      decTree(root->getRight(), in, prefix, i+1);
    }
  }

  
}

int readTree(heapNode*& root, string prefix, int i){
  if((root->getLeft() == NULL)&&(root->getRight() == NULL)){
    cout<< root->getChar();
    }
    else{
      if(prefix[i] == '0'){
	readTree(root->getLeft(), prefix, i+1);
      }
      if(prefix[i] == '1'){
	readTree(root->getRight(), prefix, i+1);
      }
    }
  return 1;
}

// main(): we want to use parameters
int main (int argc, char **argv) {
  heapNode* root;
  double in = 0;
  int s = 0;
  
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in the first section of the file: the prefix codes
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
        // add prefix to the tree
	char c = character[0];
	decTree(root, c, prefix, 0);
	// cout << "character '" << character << "' has prefix code '"
	//   << prefix << "'" << endl;
	s++;
  
    }
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
	in += readTree(root,bits,0);
        sstm << bits;
    }
    cout << endl;

    /*
    cout << in << " " << s << endl;
    
    /*
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    cout << "All the bits: " << allbits << endl;
    cout << in/allbits.length();
    */

    
    // close the file before exiting
    file.close();
}
