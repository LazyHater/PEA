#pragma once
#include <vector>
#include "path.h"
#include "AdjacencyMatrix.h"

class Algorithms
{
public:
	Algorithms();
	~Algorithms();

	static std::string vec_to_string(const std::vector<unsigned int>& vec);
	
	static Path branch_and_bound(const AdjacencyMatrix& mat);
	static Path brutefoce(const AdjacencyMatrix& mat);
};

