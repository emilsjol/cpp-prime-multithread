#include "naive.h"
#include <iostream>
#include <string>
#include <thread>
#include <vector>

int naivePrimes(int targetNumber, int numberOfThreads) {

	int n = 0;
	int temp = 0;
	bool foundPrime;
	std::vector<bool> vector;
	
	for (int i = 0; i < targetNumber; ++i) {
		vector.push_back(0);
	}
	
	while (n <= targetNumber) {
		
		temp = 2;
		bool foundPrime = true;
		
		while (temp < n) {
			if (n % temp == 0) {
				foundPrime = false;
				break;
			}
			temp++;
		}
		
		if (foundPrime) {
			vector[n] = 1;
		}
		
		n++;
	}
	
	printPrimes(vector);
	
	return 0;
}

void printPrimes(std::vector<bool> v) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == 1) {
			std::cout << i << std::endl;
		}
	}
}

/*
bool[] findPrimes(int startNumber, int endNumber) {
	int arraySize = endNumber - startNumber;
	bool[arraySize] array;
} 
*/