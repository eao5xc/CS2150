//Pat Wongwiset
//nw9ca@virginia.edu
//11/26/17
//topological.cpp

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>

//using adjacency Matrix



using namespace std;

/*!
 *\brief create a  Vertex to use in Graph
 */
class Vertex{
public:
   /*! name of vertex */
  string name;
  /*! how many vertexs point to this vertex */
  int indegree;
  /**@brief constructor
   *
   *@param str name of the vertex
   *Create vertex by passing name and initialize indegree = 0
   */
  Vertex(string str){
    name = str;
    indegree = 0;
  }
};

/*!
 *\brief create a graph containing vertexs and define relation (edges) between vertex if need to
 */

class Graph{
private:
   /**list of vertices in the graph */
  vector<Vertex*> vertices;
   /**the number of vertexs in the graph */
  int numV;
   /**the maximum number of vertexs in the graph */
  int maxV;
   /**Adjacency Matrix defined the edge between vertexs in the graph*/
  vector<vector<int> > edges;
public:
  /**@brief constructor
   *
   *Create graph by passing integer to define size of it and initialize all value in vertices = NULL and values in edges = 0.
 *@param size initialize the size of the graph
   */  
  Graph(int size){  //constructor
    numV = 0;
    maxV = size;
    vertices.resize(size);
    for(int i=0; i<size; i++){
      vertices[i] = NULL;
    }


    int row = size; 
    int col = size; 
    edges.resize(row, vector<int>(col,0));
  }
  /**@brief add_vertex
   *
   *Add vertex into the graph
   *@return void
   *@param aVertex pointer that will add to the graph
   */
  void add_vertex(Vertex* aVertex){  //add_vertex method
    bool added = true;
    
    for(int j = 0; j<maxV; j++){
      if(vertices[j] != NULL){
	string str1 = vertices[j]->name;
	string str2 = aVertex->name;
	if(str1==str2){
	  aVertex = vertices[j];
	  added = false;
	}
      }
    }
    
    if(added){ 
    vertices[numV] = aVertex;
    for(int i =0; i<maxV; i++){
      edges[numV][i] = 0;
    }
    numV++;
    }
  }


  //add_edge method
   /**@brief add_edge
   *
   *Add an edge into the graph
   *@return void
   *@param src starting vertex
   *@param dest end vertex
   */
  void add_edge(Vertex* src, Vertex* dest){ // i is a weight telling the edge exists
    this->add_vertex(src);
    this->add_vertex(dest);
    int row;
    int col;
    row = atIndex(src);
    col = atIndex(dest);
    edges[row][col] = 1;
    vertices[col]->indegree++;
  }
 /**@brief atIndex
   *
   *Finding index of the vertex in the graph
   *@return the index number of aVertex
   *@param aVertex vertex that wants to find the location (index) in the vertices list
   *@todo aVertex must be in the graph, if not the code will return -1
   */
  int atIndex(Vertex* aVertex){
    int i = 0;
    while(i < numV){
     	string str1 = vertices[i]->name;
	string str2 = aVertex->name;
	if(str1==str2){
	  return i;
	}
      i++;
    }
    return -1;
  }
  /**@brief weight
   *
   *Finding whether the edge is created between two vertexs
   *@return 1 if it exists an edge between 2 vertex, and 0 otherwise
   *@param src the starting point
   *@param dest the ended point
   *@todo src and dest must be in the graph
   */
  int weight(Vertex*& src, Vertex*& dest){
    int row = atIndex(src);
    int col = atIndex(dest);
    return edges[row][col];
  }
  /**@brief topsort
   *
   *Determine and print out whether the graph is DAG
   *@return void
   */
  void topsort(){
    queue<Vertex*> q;
    int counter = 0;
    Vertex* v,*w;
    for(int i = 0; i<numV; i++){
      v = vertices[i];
      if(v->indegree == 0){
	q.push(v);
      }
    }
    while(!q.empty()){
      v = q.front();  //get vertex of indegree 0
      cout << v->name << " ";
      q.pop();
      counter++;
      for(int i = 0; i<numV; i++){
	w = vertices[i];
	if(weight(v,w) == 1){
	  w->indegree--;
	  if(w->indegree == 0){
	    q.push(w);
	  }
	}
      }
    }
    cout << endl;

    if(counter != numV){
      cout << "cyclefound" << endl;
      }
}

  

};
/*
int main(){
  Vertex* v = new Vertex("CS");
  Vertex* a = new Vertex("CS");
  Vertex* w = new Vertex("M");
  Vertex* z = new Vertex("C");
  Graph g(100);
  // g.add_vertex(v);
  //g.add_vertex(w);
  //g.add_vertex(z);
  g.add_edge(v,w);
  g.add_edge(a,z);
  g.add_edge(z,w);
  // g.add_edge(z,a);
  g.topsort();

  return 0;
  
}
*/


int main (int argc, char **argv) {
  Graph g(100);
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in two strings
    string s1, s2;
    while( !file.eof()){ 
    file >> s1;
    file >> s2;
    // output those strings
    if((s1 == "0")&&(s2 == "0")){
	break;
      }
    Vertex* v = new Vertex(s1);
    Vertex* w = new Vertex(s2);
    g.add_edge(v,w);
    // close the file before exiting
    }

    g.topsort();
    
    file.close();
    
}


