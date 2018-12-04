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

		for(int j=0; j<adjList[i].size(); j++){
			catAL.push_back(adjList[i][j]);
		}
	}
/*
for (vector<int>::const_iterator i = catAL.begin(); i != catAL.end(); ++i)
    cout << *i << ' ';
	cout << '\n';
*/

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

	//int *arrayAL= catAL.data();	

	//int_vector<> aL(*arrayAL);
	int_vector<> aL(catAL.size(), 0, (int)ceil(sqrt(catAL.size())));
	for (int i = 0; i != catAL.size(); ++i)
		aL[i] = catAL[i];

/*
for (int i = 0; i != aL.size(); ++i)
    cout << aL[i] << ' ';
	cout << '\n';
*/

	construct_im(s,aL);
	//construct_im(s,catAL.data());

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
//	cout << "s.size " << s.size() << " lim " << lim << endl;
/*
	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i] << " ";
	}	cout<<endl;
*/
/*	for (int i = 1; i <= lim; ++i)
	{
		p = s.select(i,a);
		cout << s[p] << endl;
	}	
*/
	vector<int> bbva(1,1);
	return bbva;
}

bool CompressedGraph::checkConnection(int a, int b){

}