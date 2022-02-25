#include "naive.h"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
	
	int targetNumber;
	int numberOfThreads;
	
	if (argc == 1) { //argv[0] finns alltid, argv[0] är programnamn
		targetNumber = 100;
		numberOfThreads = 1;
	} else if (argc == 2) {
		targetNumber = std::stoi(argv[1]);
	} else if (argc == 3) {
		targetNumber = std::stoi(argv[1]);
		numberOfThreads = std::stoi(argv[2]);
	}
	
	naivePrimes(targetNumber, numberOfThreads);
	
	return 0;
}