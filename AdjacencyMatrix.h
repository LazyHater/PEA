#pragma once
#include <vector>
#include <deque>
#include <stdexcept>

class AdjacencyMatrix
{
public:
	AdjacencyMatrix() {};
	AdjacencyMatrix(const AdjacencyMatrix& obj); // Copy constructor
	~AdjacencyMatrix();

	// returns the amount of vertexes
        int getV() const;

	// returns the amount of edges
        int getE() const;

	//// lists all vertices y such that there is an edge from the vertex x to the vertex y;
	//std::deque<int> neighbors(int x) const;

	// returns the value associated with edge from verticle x to y
        int getValue(int x, int y) const;

	// sets the given value associated with edge from verticle x to y
	AdjacencyMatrix & setValue(int x, int y, int val);

	//virtual std::vector<Edge> getEdges() const;

	// generate graph with given amount of verticles and with costs of edges in range <min_value, max_value)
	AdjacencyMatrix & generate(int verticles, int min_val, int max_val);

	// returns the graph's representation as a std::string
	std::string toString() const;

	// clears the graph
	AdjacencyMatrix & clear();

	// loads the graph from a file
	AdjacencyMatrix & loadFromFile(const std::string fname);

private:
	// amount of vertexes V
	int V = 0;

	// amount of edges (v * ( v - 1 ))
	int E = 0;

	// here comes all the data
	std::vector<std::vector<int>> matrix;

	// validation
	void checkOutOfRange(int x, int y) const;
};
