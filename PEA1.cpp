// PEA1.cpp : Defines the entry point for the console application.
//
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <queue>
#include "AdjacencyMatrix.h"
#include "algorithms.h"
#include "clock.h"

//#define SILENT

std::string menu =
"\n\n1. Load from file\n"
"2. Show\n"
"3. Generate\n"
"4. Branch and bound\n"
"5. Bruteforce\n"
"6. Set seed\n"
"q. Exit\n";
int main()
{
	srand(unsigned int(time(NULL)));

	AdjacencyMatrix mat;
	Clock clock;

	char opt;
	bool quit = false;
	while (!quit) {
#ifndef SILENT
		std::cout << menu;
#endif

		std::cin >> opt;
		switch (opt) {
		case 'q': {
			quit = true;
			break;
		}
		case '1': { // load from file
#ifndef SILENT
			std::cout << "Pls provide filename: ";
#endif
			std::string fname;
			std::cin >> fname;
			mat.loadFromFile(fname);
			break;
		}
		case '2': { // show
			std::cout << mat.toString() << "\n";
			break;
		}
		case '3': { // generate
#ifndef SILENT
			std::cout << "Pls provide n: ";
#endif
			int n;
			std::cin >> n;
			mat.generateRandom(n, 0, 1000, true);
			break;
		}
		case '4': { // bnb
			clock.start();
			auto result_brut = Algorithms::branch_and_bound(mat);
			clock.stop();
			std::cout << result_brut.to_string() << "\n";
			std::cout << clock.read() << "\n";
			break;
		}
		case '5': { // brute
			clock.start();
			auto result_brut = Algorithms::brutefoce(mat);
			clock.stop();
#ifndef SILENT
			std::cout << result_brut.to_string() << "\n";
#endif
			std::cout << clock.read() << "\n";
			break;
		}
		case '6': { // seed
#ifndef SILENT
			std::cout << "Pls seed: ";
#endif
			unsigned int seed;
			std::cin >> seed;
			srand(seed);
			break;
		}
		}
	}

	return 0;
}