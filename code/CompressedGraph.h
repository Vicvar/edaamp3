#include <sdsl/bit_vectors.hpp>
#include <sdsl/wavelet_trees.hpp>
#include <vector>

class CompressedGraph{
public:
	CompressedGraph(std::vector<std::vector<int> >);
	~CompressedGraph();
	std::vector<int> getNeighbours(int);
	std::vector<int> getReverseNeighbours(int);
	bool checkConnection(int, int);
private:
	bool cCDFS(int, int, sdsl::bit_vector);
	int max_node;
	sdsl::bit_vector b;
	sdsl::rank_support_v<> rankb;
	sdsl::select_support_mcl<> selb;
	sdsl::wt_int<> s;
};