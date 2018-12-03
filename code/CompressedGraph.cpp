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

	for(int i=0; i<adjList.size(); i++){
		for(int j=0; j<adjList[i].size(); j++){
			catAL.push_back(adjList[i][j]);
		}
	}

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