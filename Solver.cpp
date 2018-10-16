#include "stdafx.h"
#include "Solver.h"
#include "AdjacencyMatrix.h"
#include <iostream>
#include <string>

Solver::Solver() {
}


Solver::~Solver() {
}



// Check if colum columnNumber can be reduced. When there is at least one 0 or every element is "inf" it can't be reduced.
bool Solver::isColumnValid(const AdjacencyMatrix & tsp, unsigned int columnNumber) {
	unsigned int infinitiesCounter = 0;

	for (auto& row : tsp.matrix) {
		if (row[columnNumber] == 0) return false;
		else if (row[columnNumber] == FLT_MAX) infinitiesCounter++;
	}

	if (infinitiesCounter == tsp.matrix.size()) return false;
	else return true;
}

// Check if row can be reduced. When there is at least one 0 or every element is "inf" it can't be reduced.
bool Solver::isRowValid(const std::vector<float>& row) {
	unsigned int infinitiesCounter = 0;

	for (auto& element : row) {
		if (element == 0) return false;
		else if (element == FLT_MAX) infinitiesCounter++;
	}

	if (infinitiesCounter == row.size()) return false;
	else return true;
}

float Solver::reduce(AdjacencyMatrix & tsp) {
	float calculatedValue = 0; // Variable holding the sum of minimal values from rows and columns

	// Rows reduction
	for (auto& row : tsp.matrix) {
		// Check if row can be reduced
		if (isRowValid(row)) {
			float minimum = FLT_MAX; // Variable holding minimum for a row

			// Find minimum
			for (auto& element : row) {
				if (element < minimum) {
					minimum = element;
				}
			}

			calculatedValue += minimum;

			// Subtract minimum from row's elements
			for (auto& element : row) {
				// Skip "inf" (inf - minimum = inf)
				if (element != FLT_MAX) {
					element -= minimum;
				}
			}
		}
	}

	//std::cout << tsp.toString() << "\n" << calculatedValue << "\n";

	// Columns reduction
	for (unsigned int i = 0; i < tsp.matrix.size(); i++) {
		// Check if column can be reduced
		if (isColumnValid(tsp, i)) {
			float minimum = FLT_MAX; // Variable holding minimum for a column

			// Find minimum
			for (unsigned int j = 0; j < tsp.matrix.size(); j++) {
				if (tsp.matrix[j][i] < minimum) {
					minimum = tsp.matrix[j][i];
				}
			}

			calculatedValue += minimum;

			// Subtract minimum from column's elements
			for (unsigned int j = 0; j < tsp.matrix.size(); j++) {
				if (tsp.matrix[j][i] != FLT_MAX) {
					tsp.matrix[j][i] -= minimum;
				}
			}
		}
	}

	//std::cout << tsp.toString() << "\n" << calculatedValue << "\n";
	return calculatedValue;
}

std::vector<int> Solver::findPath(const AdjacencyMatrix& tsp, unsigned int startVertex) {
	std::cout << "Finding path..." << std::endl;

	std::vector<int> path; // Vector containing the path
	std::vector<bool> visitedVertices; // Vector for marking visited vertices
	visitedVertices.resize(tsp.numberOfVertices);

	// 1. Copy the matrix and change 0s to Infs
	AdjacencyMatrix copy(tsp);
	for (auto& row : copy.matrix) {
		for (auto& element : row) {
			if (element == 0) element = FLT_MAX;
		}
	}
	std::cout << copy.toString() << std::endl;

	// 2. Lower bound, starting vertex
	float lowerBound = reduce(copy);
	visitedVertices[startVertex] = true; // Starting vertex visited
	path.push_back(startVertex); // Starting from start vertex

	//std::cout << copy.toString() << std::endl;
	return path;
}
