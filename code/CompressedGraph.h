#include <sdsl/bit_vectors.hpp>
#include <sdsl/wavelet_trees.hpp>
#include <vector>

class CompressedGraph{
private:
	void cCDFS(int, int, sdsl::bit_vector*);
	int max_node;
	sdsl::bit_vector b;
	sdsl::rank_support_v<1> rankb;
	sdsl::select_support_mcl<1> selb;
	sdsl::wt_int<> s;
public:
	CompressedGraph(std::vector<std::vector<int> >);
	~CompressedGraph();
	std::vector<int> getNeighbours(int);
	std::vector<int> getReverseNeighbours(int);
	bool checkConnection(int, int);
	int getSize();

};