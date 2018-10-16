#include "path.h"
#include <sstream>


void Path::append(unsigned int city, const AdjacencyMatrix& matrix)
{
	this->cost += matrix.getEdge(this->path.back(), city);
	this->path.push_back(city);
}

std::string Path::to_string() const {
	std::stringstream ss;
	ss << "<cost: " << cost <<" leave_cost: "<< this->lower_bound << " path: [";
	for (int i = 0; i < (int)this->path.size() - 1; i++) {
		ss << this->path[i] << ", ";
	}

	if (this->path.size() > 0)
		ss << this->path[this->path.size() - 1];
	ss << "]>";
	return ss.str();
}

Path::Path()
{
}

Path::Path(unsigned int init_city)
{
	this->path.push_back(init_city);
}

Path::Path(float cost, const std::vector<unsigned int> path)
{
	this->cost = cost;
	this->path = path;
}

Path::~Path()
{
}

//
//bool Path::operator<(const Path & other) const
//{
//	if (other.lower_bound == this->lower_bound) 
//		return other.getPath().size() > this->getPath().size();
//	else 
//		return (this->lower_bound) > (other.lower_bound);
//}

bool Path::operator<(const Path & other) const
{
	return (this->lower_bound) > (other.lower_bound);
}
