#pragma once
#include <vector>
#include <deque>

class AdjacencyMatrix {
public:
	size_t numberOfVertices = 0;

	AdjacencyMatrix() {};
	AdjacencyMatrix(std::string fname); // Read from file
	AdjacencyMatrix(unsigned int numberOfVertices); // Fill with zeros
	AdjacencyMatrix(const AdjacencyMatrix& obj); // Copy constructor
	~AdjacencyMatrix();

	std::vector<std::vector<unsigned int>> matrix; // Adjacency matrix

	std::deque<unsigned int> getNeighbors(unsigned int x) const;
	bool isAdjacent(unsigned int x, unsigned int y) const;
	AdjacencyMatrix& addVertex(unsigned int x);

	bool loadFromFile(const std::string fname);
	void generateRandom(unsigned int numberOfVertices, unsigned int from, unsigned int to, bool isDirected);

	std::string toString() const;
	AdjacencyMatrix & clear();

	inline unsigned int getEdge(unsigned int from, unsigned int to) const { return this->matrix[from][to]; };

private:
	void resizeAndClearMatrix(unsigned int numberOfVertices);
};