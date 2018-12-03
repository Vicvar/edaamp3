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
	sdsl::bit_vector b;
	sdsl::wt_int<> s;
};