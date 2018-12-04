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

/*	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
*/	
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
	if (mat[a][b])
		return true;
	return false;
}

void MatrizAdyacencia::add(int a, int b){
	mat[a][b]=true;
	/*
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	*/
}
