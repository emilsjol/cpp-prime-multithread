#include "naive.h"
#include <iostream>
#include <string>
#include <thread>
#include <vector>

int naivePrimes(int targetNumber, int numberOfThreads) {

	int n = 0;
	int temp = 0;
	std::vector<bool> vector;
	
	for (int i = 0; i < targetNumber; ++i) {
		vector.push_back(0);
	}
	
	while (n <= targetNumber) {
		
		if (isPrime(n)) {
			vector[n] = 1;
		}
		
		n++;
	}
	
	printPrimes(vector);
	
	return 0;
}

bool isPrime(int n) {
	
	for (int temp = 2; temp < n; ++temp) {
		if (n % temp == 0) {
			return false;
		}
	}
	
	return true;

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