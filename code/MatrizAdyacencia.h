#include <vector>
using namespace std;

class MatrizAdyacencia{
	private:
		int size;
		bool **mat;
		void DFS(int a, int b, bool visited[]);
	public:
		MatrizAdyacencia(int n);
		~MatrizAdyacencia();
		vector<int> getNeighbours(int a);
		vector<int> getReverseNeighbours(int a);
		bool checkConnection(int a, int b);
		void add(int a, int b);
		int getSize();
};