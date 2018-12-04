#include "CompressedGraph.h"
#include <sdsl/bit_vectors.hpp>
#include <sdsl/wavelet_trees.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sdsl;

CompressedGraph::CompressedGraph(vector<vector<int> > adjList){
	vector<int> catAL;
	
	int bsize = adjList.size();//tamaño de b

	for(int i=0; i<adjList.size(); i++){

		bsize += adjList[i].size();

		catAL.push_back(-1);
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

	int_vector<> aL(catAL.size(), 0, (int)ceil(sqrt(adjList.size())));
	for (int i = 0; i != catAL.size(); ++i)
		aL[i] = catAL[i];
	
	construct_im(s,aL);

	rankb = rank_support_v<>(&b);
	selb = select_support_mcl<>(&b);
}

CompressedGraph::~CompressedGraph(){

}

vector<int> CompressedGraph::getNeighbours(int a){
/*To retrieve the i-th neighbor of a node v,
we compute the starting point of the list of v, l ← select 1 (B, v), and then
access S[l + i − 1].*/

}

vector<int> CompressedGraph::getReverseNeighbours(int a){
/*To retrieve the i-th reverse neighbor of a node v, we compute
p ← select v (S, i) to find the i-th time that v is mentioned in an adjacency
list, and then compute with rank 1 (B, p) the owner of the list where v is men-
tioned.*/
	int p,lim;
	lim = s.rank(s.size(),a);
	vector<int> ret;
	for (int i = 1; i <= lim; ++i)
	{
		p = s.select(i,a);
		ret.push_back(rankb.rank(p) -1);
	}	
	return ret;
}

bool CompressedGraph::checkConnection(int a, int b){

}
