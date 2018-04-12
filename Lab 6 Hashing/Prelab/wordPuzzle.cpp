//Pat Wongwiset
//nw9ca
//wordPuzzle.cpp
//10/11/17

//big-theta running time of the word-search: n (Due to hash function, the program has lots of colision. Thus, the worst case is linear when searching.)

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <typeinfo>
#include "hashTable.h"
#include "timer.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// Forward declarations
bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);



/** The main() function shows how to call both the readInGrid()
 * function as well as the getWordInGrid() function.
 */
/*int main() {
    // to hold the number of rows and cols in the input file
    int rows, cols;
    // attempt to read in the file
    bool result = readInGrid ("5x8.grid.txt", rows, cols);
    // if there is an error, report it
    if ( !result ) {
        cout << "Error reading in file!" << endl;
        exit(1); // requires the <stdlib.h> #include header!
    }
    // Get a word (of length 10), starting at position (2,2) in the
    // array, in each of the 8 directions
    cout << endl;
    for ( int i = 0; i < 8; i++ )
        cout << i << ": " << getWordInGrid(2,2,i,10,rows,cols) << endl;
    // All done!
    return 0;
}
*/




/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columnss as specified in the input file;
 *             as this is a reference, it is set by the function.
 */

bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
            //cout << grid[r][c];
        }
	// cout << endl;
    }
    // return success!
    return true;
}



/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static char[][] variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A char* containing the letters in the provided direction
 *         (NOTE: it is returned in a static char array).
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}

int main(int argc, char** argv){
  //cout << "The dictionary file: " << argv[1] << endl;
  //cout << "The grid file: " << argv[2] << endl;
  
  
  timer t;
  string line;
  int sizeDict = 0;
  
  string filename = argv[1]; //keep track how many elements in dictionary file to initiate the size of hash table
  ifstream file(filename.c_str());
  if (file.is_open())
  {
    while ( getline(file,line) )
    {
      sizeDict++;
    }
    file.close();
  }

  else{
    cout << "File Not Found";
  }

  
  hashTable* hT = new hashTable(sizeDict);

  
    
  ifstream myfile(filename.c_str()); //read file again to insert elements in the hash table
  if (myfile.is_open())
  {
    while ( getline(myfile,line) )
    {
      hT->insert(line); //<-cannot insert
    }
    myfile.close();
  }

  else{
    cout << "File Not Found";
  }

	    
  int rows, cols;
  bool result = readInGrid (argv[2], rows, cols);
    // if there is an error, report it
    if ( !result ) {
        cout << "Error reading in file!" << endl;
        exit(1); // requires the <stdlib.h> #include header!
    }

    //cout << endl;

    int k = 0;

    t.start();
    
    for( int r = 0; r < rows; r++){
      for(int c = 0; c < cols; c++){
	for ( int i = 0; i < 8; i++ ){
	  bool printed = true;
	  for( int a = 3; a <= 22; a++){
	  string x = getWordInGrid(r,c,i,a,rows,cols);
	  //cout << x << endl;
	  string result = hT->find(x);
	  //cout << result  << endl;
	  if(result != "" && result.length() > 2 && printed){
	    k++;
	    if( i == 0){
	      cout << "N (" << r << ", " << c << "):   " << result << endl;
	      printed = false;
	    }
	    if( i == 1){
	      cout << "NE(" << r << ", " << c << "):   " << result << endl;
	      printed = false;
	    }
	    if( i == 2){
	      cout << "E (" << r << ", " << c << "):   " << result << endl;
	       printed = false;
	    }	    
	    if( i == 3){
	      cout << "SE(" << r << ", " << c << "):   " << result << endl;
	       printed = false;
	    }
	     if( i == 4){
	      cout << "S (" << r << ", " << c << "):   " << result << endl;
	       printed = false;
	    }
	     if( i == 5){
	      cout << "SW(" << r << ", " << c << "):   " << result << endl;
	       printed = false;
	    }
	    if( i == 6){
	      cout << "W (" << r << ", " << c << "):   " << result << endl;
	       printed = false;
	    }
	    if( i == 7){
	      cout << "NW(" << r << ", " << c << "):   " << result << endl;
	       printed = false;
	    }
	  }
	}
      }
      }
    }
    t.stop();
    cout << k << " words found" << endl;
    cout << "Found all words in " <<  t.getTime() << " seconds" << endl;
       
      
	
	       		      
    return 0;

    
    }


/*
int main(){
   hashTable* hT = new hashTable();
   cout << hT->getSize() << endl;
   cout << getNextPrime(hT->getSize()) << endl;
   string s = "s";
   cout << s[0]*3*pow(3,2) << endl;
   cout << typeid(s).name()<< endl;

   //run hash fn faster
   cout << hT->hashFunct("JJ") << endl;
   cout << hT->hashFunct("IK") << endl;
    hT->insert("JJ");
    hT->insert("IK");
   cout << hT->find("JJ") << endl;
   cout << hT->find("IK") << endl;
    cout << hT->find("I") << endl;
   return 0;
}
*/



  
  
