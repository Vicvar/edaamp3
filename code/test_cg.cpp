#include "MatrizAdyacencia.h"
#include "ListaAdyacencia.h"
#include "CompressedGraph.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sdsl/bit_vectors.hpp>
#include <sdsl/util.hpp>
#include <sdsl/wavelet_trees.hpp>

using namespace std;
using namespace sdsl;
int main(int argc, char const *argv[]){
	if(argc !=2 ){
		cout << "Falta archivo" << endl;
		return 0;
	}
	int n;
//	cin >> n;
	ifstream fn(argv[1]);
	fn >> n;

	MatrizAdyacencia ma(n); 
	ListaAdyacencia li(n); 
	
	int a, b;
	while (fn.good()) {
		fn >> a >> b;
		ma.add(a,b);
		li.add(a,b);
	}

	vector<int> r;
	r=ma.getReverseNeighbours(2);
	for (vector<int>::const_iterator i = r.begin(); i != r.end(); ++i)
	cout << *i << ' ';
	cout << '\n';

	r=li.getReverseNeighbours(2);
	for (vector<int>::const_iterator i = r.begin(); i != r.end(); ++i)
	cout << *i << ' ';
	cout << '\n';

	CompressedGraph cg(li.getL());
	r=cg.getReverseNeighbours(2);
	for (vector<int>::const_iterator i = r.begin(); i != r.end(); ++i)
	cout << *i << ' ';
	cout << '\n';

	cout<<cg.checkConnection(17,20)<<endl;

	return 0;
}
