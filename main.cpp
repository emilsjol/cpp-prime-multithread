#include "naive.h"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
	
	int targetNumber = 100;
	int numberOfThreads = 1;
	bool verbose = false;
	bool time = false;
	bool benchmark = false;
	
	if (argc == 1) { //argv[0] finns alltid, argv[0] är programnamn
		targetNumber = 100;
		numberOfThreads = 1;
		verbose = true;
		time = true;
		benchmark = false;
	} else {
		for (int i = 1; i < argc; ++i) {
			if (i == 1) {
				interpretArgument(argv[i], &verbose, &time, &benchmark, &targetNumber);
			} else if (i == 2) {
				interpretArgument(argv[i], &verbose, &time, &benchmark, &numberOfThreads);
			} else {
				interpretArgument(argv[i], &verbose, &time, &benchmark, &targetNumber);
			}
		}
	}

	naivePrimes(targetNumber, numberOfThreads, verbose, time, benchmark);
	
	return 0;
}

void interpretArgument(std::string arg, bool *v, bool *t, bool *b, int *n) {
	if (arg[0] == '-') {
		switch(arg[1]) {
			case 'v': *v = true; //verbose
					return;
			case 't': *t = true; //time
					return;
			case 'b': *b = true; //benchmark
					return;
		}
	}
	*n = std::stoi(arg); //number, either target or number of threads
	return;
}