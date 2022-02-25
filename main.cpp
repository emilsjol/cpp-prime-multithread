#include "naive.h"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
	
	int targetNumber;
	int n = 1;
	int temp = 0;
	bool foundPrime;
	
	if (argc == 1) { //argv[0] finns alltid, argv[0] är programnamn
		targetNumber = 100;
	} else {
		targetNumber = std::stoi(argv[1]);
	}
	
	findPrimes(targetNumber);
	
	return 0;
}