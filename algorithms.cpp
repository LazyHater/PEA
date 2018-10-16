#include "algorithms.h"
#include <sstream>
#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>
//#define SILENT

Algorithms::Algorithms()
{
}


Algorithms::~Algorithms()
{
}


std::string Algorithms::vec_to_string(const std::vector<unsigned int>& vec)
{
	std::stringstream ss;
	ss << "[";
	for (int i = 0; i < (int)vec.size() - 1; i++) {
		ss << vec[i] << ", ";
	}

	if (vec.size() > 0)
		ss << vec[vec.size() - 1];
	ss << "]";
	return ss.str();
}


Path Algorithms::branch_and_bound(const AdjacencyMatrix & mat)
{
	std::priority_queue<Path, std::vector<Path>> queue;
	Path best_path(0);
	queue.push(best_path);
	bool leaf_reached = false;
	size_t peek_size = 0;

	while (!queue.empty()) {
		size_t size = queue.size();
		if (size > peek_size) peek_size = size;

		auto current_path = queue.top();
		queue.pop();

		if (!leaf_reached || (current_path.lower_bound < best_path.getCost())) {

			for (unsigned int child = 1; child < mat.matrix.size(); child++) {
				bool visited = false;
				for (const unsigned int tmp : current_path.getPath()) {
					if (child == tmp) {
						visited = true;
						break;
					}
				}
				if (visited) continue;

				auto new_path = current_path;
				new_path.append(child, mat);

				if (new_path.getPath().size() == mat.matrix.size()) {
					// here leaf
					new_path.append(0, mat);
					if (!leaf_reached || (new_path.lower_bound < best_path.getCost())) {
						best_path = new_path;
						leaf_reached = true;
#ifndef SILENT
						std::cout << "New best!: " << best_path.to_string() << "\n";
#endif
					}
				}
				else {
					// not leaf
					new_path.lower_bound = new_path.getCost();
					for (unsigned int from = 1; from < mat.matrix.size(); from++) {
						bool visited = false;
						for (const unsigned int in_path : current_path.getPath()) {
							if (from == in_path) {
								visited = true;
								break;
							}
						}
						if (visited) continue;

						unsigned int min_cost = UINT_MAX;
						for (unsigned int to = 0; to < mat.matrix.size(); to++) {
					
							if (from == child && to == 0) continue;
							if (from == to) continue;

							bool visited = false;
							for (int l = 1; l < new_path.getPath().size(); l++) {
								if (to == new_path.getPath()[l]) {
									visited = true;
									break;
								}
							}
							if (visited) continue;

							unsigned int cost = mat.getEdge(from, to);
							if (cost < min_cost) {
								min_cost = cost;
							}
						}
						new_path.lower_bound += min_cost;
					}
					if (!leaf_reached || ((new_path.lower_bound) < best_path.getCost())) {
						queue.push(new_path);
					}
				}
			}
		}
		else {
			break;
		}
	}
#ifndef SILENT
	printf("Queue peek at %llu!\n", peek_size);
#endif
	return best_path;
}


Path Algorithms::brutefoce(const AdjacencyMatrix & mat)
{
	std::vector<unsigned int> path;
	for (int i = 0; i < mat.matrix.size(); i++) {
		path.push_back(i);
	}

	unsigned int min_cost = UINT_MAX;
	std::vector<unsigned int> min_path;
	do {
		unsigned int path_cost = 0;
		for (int i = 0; i < path.size() - 1; i++) {
			path_cost += mat.getEdge(path[i], path[i + 1]);
		}
		path_cost += mat.getEdge(path[path.size() - 1], path[0]);
		if (path_cost < min_cost) {
			min_cost = path_cost;
			min_path = path;
		}
	} while (std::next_permutation(path.begin(), path.end()));

	min_path.push_back(0);
	return Path(min_cost, min_path);
}

