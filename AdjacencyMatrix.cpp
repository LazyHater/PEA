#include "AdjacencyMatrix.h"
#include <climits>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <iterator>

AdjacencyMatrix::AdjacencyMatrix(std::string fname) {
	loadFromFile(fname);
}

AdjacencyMatrix::AdjacencyMatrix(unsigned int numberOfVertices) {
	resizeAndClearMatrix(numberOfVertices);
}

AdjacencyMatrix::AdjacencyMatrix(const AdjacencyMatrix & obj) {
	for (auto vec : obj.matrix)
		matrix.push_back(std::vector<unsigned int>(vec));
	numberOfVertices = obj.numberOfVertices;
}

AdjacencyMatrix::~AdjacencyMatrix() {
}

void AdjacencyMatrix::resizeAndClearMatrix(unsigned int numberOfVertices) {
	matrix.resize(numberOfVertices);
	for (auto& row : matrix) {
		row.resize(numberOfVertices);
	}
	this->numberOfVertices = matrix.size();
}

bool AdjacencyMatrix::isAdjacent(unsigned int x, unsigned int y) const {
	return matrix[x][y] != 0;
}

std::deque<unsigned int> AdjacencyMatrix::getNeighbors(unsigned int x) const {
	std::deque<unsigned int> tmp;
	for (unsigned int i = 0; i < matrix.size(); i++)
		if (matrix[x][i] != 0)
			tmp.push_back(i);
	return tmp;
}

AdjacencyMatrix & AdjacencyMatrix::addVertex(unsigned int x) {
	while (x >= matrix.size()) {
		for (auto& vec : matrix) {
			vec.push_back(0);
		}
		std::vector<unsigned int> vec;
		for (unsigned int i = 0; i <= matrix.size(); i++)
			vec.push_back(0);

		matrix.push_back(vec);
		numberOfVertices++;
	}
	return *this;
}

std::string AdjacencyMatrix::toString() const {
	std::stringstream ss;
	ss << "Adjacency matrix, V: " << numberOfVertices << "\n";
	for (auto& vec : matrix) {
		for (unsigned int val : vec) {
			ss << std::setw(8) << val;
		}
		ss << "\n";
	}
	return ss.str();
}

AdjacencyMatrix & AdjacencyMatrix::clear() {
	numberOfVertices = 0;
	matrix.clear(); 
	return *this;
}


bool AdjacencyMatrix::loadFromFile(const std::string fname) {
	clear();
	unsigned int size;
	std::ifstream file(fname, std::ios::out);
	if (file.is_open()) {
		file >> size;
		printf("size %lu\n", size);
		for (unsigned int j = 0; j < size; j++) {
			std::vector<unsigned int> vec(size);
			for (unsigned int i = 0; i < size; i++) {
				file >> vec[i];
				printf("%llu\n", vec[i]);

			}
			matrix.push_back(vec);
		}
		file.close();
		return true;
	}
	else {
		std::cerr << "Cannot open file!\n";
		system("pause");
		return false;
	}
}

void AdjacencyMatrix::generateRandom(unsigned int numberOfVertices, unsigned int from, unsigned int to, bool isDirected) {
	resizeAndClearMatrix(numberOfVertices);
	for (unsigned int i = 0; i < matrix.size(); i++) {
		for (unsigned int j = 0; j < matrix[i].size(); j++) {
			if (isDirected == false) {
				if (i != j) {
					unsigned int val = (unsigned int)(from + (rand() % static_cast<int>(to - from + 1)));
					matrix[i][j] = val;
					matrix[j][i] = val;
				}
				else {
					continue;
				}
			}
			else {
				if (i != j) matrix[i][j] = (unsigned int)(from + (rand() % static_cast<int>(to - from + 1)));
			}

		}
	}
}
