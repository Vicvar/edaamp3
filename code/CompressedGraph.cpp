#include "CompressedGraph.h"
#include <sdsl/bit_vectors.hpp>
#include <sdsl/wavelet_trees.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sdsl;

CompressedGraph::CompressedGraph(vector<vector<int> > adjList){
	//Constructs Compressed Graph from adjacency list
	vector<int> catAL;
	
	int bsize = adjList.size();//tamaño de b

	for(int i=0; i<adjList.size(); i++){

		bsize += adjList[i].size();

		for(int j=0; j<adjList[i].size(); j++){
			catAL.push_back(adjList[i][j]);
		}
	}

	b = bit_vector(bsize,0);
	b[0] = 1;
	int k = 0;
	for(int i=0; i<adjList.size()-1; i++){
		k += adjList[i].size() + 1;
		b[k] = 1;
	}
/*for (int i = 0; i < b.size(); ++i)
{
	cout << b[i];
}	cout << endl;*/


	int * arrayAL= catAL.data();

	int_vector<> aL(*arrayAL);

	construct_im(s,aL);

}

CompressedGraph::~CompressedGraph(){

}

vector<int> CompressedGraph::getNeighbours(int a){

}

vector<int> CompressedGraph::getReverseNeighbours(int a){

}

bool CompressedGraph::checkConnection(int a, int b){

}