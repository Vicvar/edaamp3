#include <vector>
using namespace std;

class MatrizAdyacencia{
	private:
		int size;
		bool **mat;
	public:
		MatrizAdyacencia(int n);
		~MatrizAdyacencia();
		vector<int> getNeighbours(int a);
		vector<int> getReverseNeighbours(int a);
		bool checkConnection(int a, int b);
		void add(int a, int b);
};