#pragma once
#include <vector>
#include <string>

#include "AdjacencyMatrix.h"

class Path
{
public:
	void append(unsigned int city, const AdjacencyMatrix& matrix);
	inline float getCost() const { return this->cost; };
	inline const std::vector<unsigned int>& const getPath() const { return this->path; };
	std::string to_string() const;
	Path();
	Path(unsigned int init_city);
	Path(float cost, const std::vector<unsigned int> path);
	~Path();
	float lower_bound = 0;

	bool operator<(const Path& other) const;
private:
	float cost = 0;
	std::vector<unsigned int> path;


};

