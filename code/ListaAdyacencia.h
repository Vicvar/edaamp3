#include <vector>
using namespace std;

class ListaAdyacencia{
	private:
		vector<vector<int> > lout;
		vector<vector<int> > lin;
	public:
		ListaAdyacencia(int n);
		~ListaAdyacencia();
		vector<int> getNeighbours(int a);
		vector<int> getReverseNeighbours(int a);
		bool checkConnection(int a, int b);
		void add(int a, int b);
		vector<vector<int> > getL();
};