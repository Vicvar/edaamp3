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
	vector<int>::iterator it = find (lout[a].begin(), lout[a].end(), b);
	if (it != lout[a].end())
		return true;
	return false;
}

void ListaAdyacencia::add(int a, int b){
	lout[a].push_back(b);
	lin[b].push_back(a);
}

vector<vector<int> > ListaAdyacencia::getL(){
	return lout;
}