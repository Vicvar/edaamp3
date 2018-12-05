#include "CompressedGraph.h"
#include "ListaAdyacencia.h"
#include "MatrizAdyacencia.h"
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <utility>
#include <set>
#include <ctime>
#include <algorithm>

#define NTEST 10

using namespace std;

int nnodes;//global number of nodes

vector<pair<int,int> > readFile(char *file){
	ifstream fin(file);
	vector<pair<int, int> > res;
	int first, second;
	map<int, int> new_ids;

	while(fin.good()){
		fin>>first>>second;
		
		//asign new ids starting from 0
		if(new_ids.find(first)==new_ids.end())
			new_ids.insert(make_pair(first,new_ids.size()));
		first=new_ids[first];
		
		if(new_ids.find(second)==new_ids.end())
			new_ids.insert(make_pair(second,new_ids.size()));
		second=new_ids[second];

		res.push_back(make_pair(first,second));
	}

	nnodes=new_ids.size();

	return res;
}

vector<pair<int,int> > genGraph(int nn, int ne){
	vector<pair<int,int> > res;

	int cne=0;

	pair<int,int> aux;

	set<pair<int,int> > edges;

	while(cne<ne){
		aux=make_pair(rand()%nn, rand()%nn);
		if(edges.find(aux)==edges.end()){
			edges.insert(aux);
			res.push_back(aux);
			cne++;
		}
	}

	nnodes=nn;

	return res;
}

int main(int argc, char* argv[]){

	if(argc!=3 && argc!=2){
		cout<<"Generate graph and test different implementations"<<endl;
		cout<<"Usage: "<<endl;
		cout<<argv[0]<<" 'number of nodes' 'number of edges'"<<endl;
		cout<<"or"<<endl;
		cout<<argv[0]<<" 'edge list file name'"<<endl;
		return 1;
	}

	vector<pair<int,int> > edgeList;

	if(argc==3)
		edgeList=genGraph(atoi(argv[1]), atoi(argv[2]));

	else if(argc==2)
		edgeList= readFile(argv[1]);


	MatrizAdyacencia ma(nnodes); 
	ListaAdyacencia li(nnodes); 

	pair<int,int> aux;

	for(int i=0; i<edgeList.size(); i++){
		aux=edgeList[i];
		ma.add(aux.first, aux.second);
		li.add(aux.first, aux.second);
	}

	CompressedGraph cg(li.getL());

	cout<<"Tamaño MatrizAdyacencia: "<<ma.getSize()<<endl;
	cout<<"Tamaño ListaAdyacencia: "<<li.getSize()<<endl;
	cout<<"Tamaño CompressedGraph: "<<cg.getSize()<<endl;

	clock_t start, finish;

	vector<int> test_nodes;

	for(int i=0; i<NTEST; i++){
		test_nodes.push_back(edgeList[rand()%edgeList.size()].first);
		test_nodes.push_back(edgeList[rand()%edgeList.size()].second);
	}

	random_shuffle(test_nodes.begin(), test_nodes.end());


	//getNeighbours
	start=clock();

	for(int i=0; i<test_nodes.size(); i+=2){
		ma.getNeighbours(test_nodes[i]);
	}

	cout<<"Tiempo getNeighbours MatrizAdyacencia"<<(clock()-start)/(double)CLOCKS_PER_SEC<<endl;

	start=clock();

	for(int i=0; i<test_nodes.size(); i+=2){
		li.getNeighbours(test_nodes[i]);
	}

	cout<<"Tiempo getNeighbours ListaAdyacencia"<<(clock()-start)/(double)CLOCKS_PER_SEC<<endl;


	start=clock();

	for(int i=0; i<test_nodes.size(); i+=2){
		cg.getNeighbours(test_nodes[i]);
	}

	cout<<"Tiempo getNeighbours CompressedGraph"<<(clock()-start)/(double)CLOCKS_PER_SEC<<endl;

	//getReverseNeighbours
	start=clock();

	for(int i=0; i<test_nodes.size(); i+=2){
		ma.getReverseNeighbours(test_nodes[i]);
	}

	cout<<"Tiempo getReverseNeighbours MatrizAdyacencia"<<(clock()-start)/(double)CLOCKS_PER_SEC<<endl;

	start=clock();

	for(int i=0; i<test_nodes.size(); i+=2){
		li.getReverseNeighbours(test_nodes[i]);
	}

	cout<<"Tiempo getReverseNeighbours ListaAdyacencia"<<(clock()-start)/(double)CLOCKS_PER_SEC<<endl;


	start=clock();

	for(int i=0; i<test_nodes.size(); i+=2){
		cg.getReverseNeighbours(test_nodes[i]);
	}

	cout<<"Tiempo getReverseNeighbours CompressedGraph"<<(clock()-start)/(double)CLOCKS_PER_SEC<<endl;

	//checkConnection
	start=clock();

	for(int i=0; i<test_nodes.size(); i+=2){
		ma.checkConnection(test_nodes[i],test_nodes[i+1]);
	}

	cout<<"Tiempo checkConnection MatrizAdyacencia"<<(clock()-start)/(double)CLOCKS_PER_SEC<<endl;

	start=clock();

	for(int i=0; i<test_nodes.size(); i+=2){
		li.checkConnection(test_nodes[i],test_nodes[i+1]);
	}

	cout<<"Tiempo checkConnection ListaAdyacencia"<<(clock()-start)/(double)CLOCKS_PER_SEC<<endl;


	start=clock();

	for(int i=0; i<test_nodes.size(); i+=2){
		cg.checkConnection(test_nodes[i],test_nodes[i+1]);
	}

	cout<<"Tiempo checkConnection CompressedGraph"<<(clock()-start)/(double)CLOCKS_PER_SEC<<endl;
}