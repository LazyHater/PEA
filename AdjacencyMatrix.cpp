#include "AdjacencyMatrix.h"
#include <climits>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <deque>

AdjacencyMatrix::AdjacencyMatrix(const AdjacencyMatrix & obj)
{
	for (auto vec : obj.matrix)
		matrix.push_back(std::vector<int>(vec));
	V = obj.V;
	E = obj.E;
}

AdjacencyMatrix::~AdjacencyMatrix()
{
}

int AdjacencyMatrix::getV() inline const { return V; };
int AdjacencyMatrix::getE() inline const { return E; }; 


//std::deque<int> AdjacencyMatrix::neighbors(int x) const
//{
//	std::deque<int> tmp;
//
//	for (int i = 0; i < matrix.size(); i++)
//		tmp.push_back(i);
//
//	return tmp;
//}
//
AdjacencyMatrix & AdjacencyMatrix::setValue(int x, int y, int val)
{
#ifdef _DEBUG
	checkOutOfRange(x, y);
#endif

	matrix[x][y] = val;

	return *this;
}

int AdjacencyMatrix::getValue(int x, int y) const
{
#ifdef _DEBUG
	checkOutOfRange(x, y);
#endif

	return matrix[x][y];
}

std::string AdjacencyMatrix::toString() const
{
	std::stringstream ss;
	ss << "Adjacency matrix, V: " << V << " E: " << E << "\n";
	for (auto& vec : matrix) {
		for (int val : vec) {
				ss << std::setw(3) << val;
			ss << " ";
		}
		ss << "\n";
	}
	return ss.str();
}

AdjacencyMatrix & AdjacencyMatrix::clear()
{
	V = 0;
	E = 0;
	matrix.clear(); // Clear the matrix
	return *this;
}
//
//std::vector<Edge> AdjacencyMatrix::getEdges() const {
//	std::vector<Edge> edges;
//	edges.reserve(E);
//	for (int x = 0; x < V; x++)
//		for (int y = 0; y < V; y++)
//			if (adjacent(x, y))
//				edges.push_back(Edge(x, y, getEdgeValue(x, y)));
//	return edges;
//}

AdjacencyMatrix & AdjacencyMatrix::loadFromFile(const std::string fname)
{
	clear();
	int size;
	std::ifstream file(fname, std::ios::out);
	if (file.is_open()) {
		file >> size;
		V = size;
		E = size*(size-1);
		matrix.reserve(size);
		for (int j = 0; j < size; j++) {
			std::vector<int> vec(size);
			for (int i = 0; i < size; i++)
				file >> vec[i];
			matrix.push_back(vec);
		}
		file.close();
		return *this;
	}
	else {
		throw std::runtime_error("Could not open file");
	}
}

AdjacencyMatrix & AdjacencyMatrix::generate(int verticles, int min_val, int max_val)
{
	clear();
	V = verticles;
	E = verticles*(verticles -1);
	matrix.reserve(verticles);

	for (int j = 0; j < verticles; j++) {
		std::vector<int> vec(verticles);
		for (int i = 0; i < verticles; i++)
			vec[i] = (i != j) ? rand() % (max_val - min_val) + min_val : 0;
		matrix.push_back(vec);
	}

	return *this;
}

void AdjacencyMatrix::checkOutOfRange(int x, int y) const {
	if ((x >= matrix.size()) || (y >= matrix.size())) {
		char buffer[100];
		sprintf_s(buffer, "Out of range! x: %i y: %i max: %i", x, y, matrix.size());
		throw std::out_of_range(buffer);
	}
}