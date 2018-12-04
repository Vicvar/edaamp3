#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "MatrizAdyacencia.h"
using namespace std;

MatrizAdyacencia::MatrizAdyacencia(int n){
	size=n;
	
	mat = new bool *[n];
	
	for(int i = 0; i < n; i++)
		mat[i] = new bool[n];	
}

MatrizAdyacencia::~MatrizAdyacencia(){

}

vector<int> MatrizAdyacencia::getNeighbours(int a){
	vector<int> ret;
	for (int i = 0; i < size; ++i){
		if(mat[a][i])
			ret.push_back(i);
	}
	return ret;
}
vector<int> MatrizAdyacencia::getReverseNeighbours(int a){
	vector<int> ret;
	for (int i = 0; i < size; ++i){
		if(mat[i][a])
			ret.push_back(i);
	}
	return ret;
}
bool MatrizAdyacencia::checkConnection(int a, int b){
	bool visit[size] = {false};
	DFS(a, b, visit);
	return visit[b];
}

void MatrizAdyacencia::DFS(int a, int b, bool visited[]){
	visited[a] = true;
	if(visited[b])
		return;
	vector<int>::iterator i; 
	for (int i = 0; i != size; ++i) 
		if (mat[a][i] && !visited[i]) 
			DFS(i,  b, visited); 
} 

void MatrizAdyacencia::add(int a, int b){
	mat[a][b]=true;
}
