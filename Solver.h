#pragma once
#include "AdjacencyMatrix.h"
#include <vector>

class Solver
{
public:
	Solver();
	~Solver();

	static bool isColumnValid(const AdjacencyMatrix& tsp, unsigned int columnNumber);
	static bool isRowValid(const std::vector<float>& row);
	static float reduce(AdjacencyMatrix& matrix);
	static std::vector<int> findPath(const AdjacencyMatrix& tsp, unsigned int startVertex);

private:

};

