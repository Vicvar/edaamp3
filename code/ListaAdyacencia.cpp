#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "ListaAdyacencia.h"
using namespace std;

ListaAdyacencia::ListaAdyacencia(int n){
	vector<int> temp;
	vector<vector<int> > aux(n,temp);
	lout = aux;
	lin = aux;
}

ListaAdyacencia::~ListaAdyacencia(){

}

vector<int> ListaAdyacencia::getNeighbours(int a){
	return lout[a];
}
vector<int> ListaAdyacencia::getReverseNeighbours(int a){
	return lin[a];
}
bool ListaAdyacencia::checkConnection(int a, int b){
	bool visit[lout.size()] = {false};
	DFS(a, b, visit);
	return visit[b];
}

void ListaAdyacencia::DFS(int a, int b, bool visited[]){
	visited[a] = true;
	if(visited[b])
		return;
	vector<int>::iterator i; 
	for (i = lout[a].begin(); i != lout[a].end(); ++i) 
		if (!visited[*i]) 
			DFS(*i,  b, visited); 
} 

void ListaAdyacencia::add(int a, int b){
	lout[a].push_back(b);
	lin[b].push_back(a);
}

vector<vector<int> > ListaAdyacencia::getL(){
	return lout;
}