//nw9ca
//Pat Wongwiset
//11/28/17
//traveling.cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;


#include "middleearth.h"


/** @brief computeDistance
 *
 * Compute the total distance when going from the origin town to the traveling destinations
 * @return the total distance along the path
 * @param me our created world
 * @param start our origin city
 * @param dests our cities that we travel to
 * @todo the dests and start must be in our created town
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests);
/** @brief printRoute
 *
 * Print out the path we visited from our defined start town and lists of traveling cities
 * @return void
 * @param start our origin city
 * @param dests lists of city that we travel to
 */
void printRoute (string start, vector<string> dests);

/** @brief main
 *
 * execution part of the program that need 6 parameters (world height, world width, number of cities, seed number, number of cities to visit) to run the program
 * @return 0 = program finished work successfully
 * @param argc number of passing parameter including the first title name (i.e. a.out
 * @param argv string parameters separated by space bar
 */
int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
   
    // YOUR CODE HERE
    string start = dests[0];
    // dests.erase(dests.begin());
    sort(dests.begin()+1, dests.end());
     vector<string> result = dests;
    int i = 0;
    //printRoute(start,dests);
    float min = computeDistance(me, start,dests);
    i++;
    while(next_permutation(dests.begin()+1, dests.end())){
      //printRoute(start, dests);
	 float dist = computeDistance(me, start, dests);
	 if( dist < min){
	   min = dist;
	   result.clear();
	   result = dests;
	   //for(unsigned int j = 0; j < dests.size(); j++){
	     //result.push_back( dests[j]);
	   //}
	 }
	 i++;
    }
    cout << "Your journey will take you along the path ";
    printRoute(start,result);
    cout << "and will have length " <<  min << endl;

    
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
    // YOUR CODE HERE
  float result = 0;
  int i = 0;
  while( i < dests.size()-1){
    result += me.getDistance(dests[i], dests[i+1]);
    i++;
      }
  result += me.getDistance(dests[dests.size()-1], start);
  return result;
  
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute (string start, vector<string> dests) {
    // YOUR CODE HERE
  int i = 0;
  while(i < dests.size()){
    cout << dests[i] << " -> ";
    i++;
  }
  cout << start << endl;

}
