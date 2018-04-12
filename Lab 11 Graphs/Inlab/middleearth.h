//nw9ca
//Pat Wongwiset
//11/28/17
//middleearth.h
#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

using namespace std;


// see the comments in the lab11 write-up, or in middleearth.cpp

/*!
 * \brief create world
 * \author CS2150 people
 * \date   2017 version
 */

class MiddleEarth {
private:
  int num_city_names/** the maximum  number of all cities */, xsize /** scope along x axis  */, ysize  /** scope along y axis  */;
  

  vector<float> xpos /**storing position of cities along x axis */, ypos /**storing position of cities along y axis */;
    
 /*! list (string vector) of created cities */
    vector<string> cities;
    
  /*! store distances between two cities */
    float *distances;
    
    /*!indices  hash_table to search cities in the world */
    map<string, int> indices;

public:
    /** @brief constructor
     *
     *It creates the world (size, number of cities, etc) of the MiddleEarth
     * @return void
     * @param xsize size along x axis
     * @param ysize size along y axis
     * @param num_cities the number of cities in the area
     * @param seed random number
     */
    MiddleEarth (int xsize, int ysize, int num_cities, int seed);
     /** @brief destructor
     *
     *It destroys the world of the MiddleEarth
     */
    ~MiddleEarth();
     /** @brief print information about cities in our created world
     *
     *This method prints information about the optional cities, selected cities and their locations
     */
    void print();
     /** @brief print information about positions, size, and distances of the cities in the world
      *
      *This method prints information in more details about the cities
      *@return void
     */
    void printTable();
    /** @brief compute the distance between 2 cities
     *
     *This method returns the distance between the two passed cities using hash table and can be loaded in Excel
     * @return distance between two cities
     * @param city1 name of city1
     * @param city2 name of city2
     */
    float getDistance (string city1, string city2);
    /** @brief List the cities that are traveled to
     *
     * This method list the cities that are traveled to from the original city until the same end city
     * @return list (string vector) of the cities traveled to
     * @param length (unsigned int) indicates how many cities we would like to pass
     */
    vector<string> getItinerary(unsigned int length);
};

#endif
