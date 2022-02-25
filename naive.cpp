#include "naive.h"
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <chrono>

int naivePrimes(int targetNumber, int numberOfThreads) {

	int n = 0;
	int temp = 0;
	std::vector<bool> vector;
	std::chrono::time_point<std::chrono::steady_clock> t1, t2, t3, t4;
	
	t1 = std::chrono::steady_clock::now();
	
	for (int i = 0; i < targetNumber; ++i) {
		vector.push_back(0);
	}
	
	t2 = std::chrono::steady_clock::now();
	
	while (n <= targetNumber) {
		
		if (isPrime(n)) {
			vector[n] = 1;
		}
		
		n++;
	}
	
	t3 = std::chrono::steady_clock::now();
	
	printPrimes(vector);
	
	t4 = std::chrono::steady_clock::now();
	std::chrono::duration<double> fillEmptyVectorTime = t2 - t1;
	std::chrono::duration<double> findPrimesTime = t3 - t2;
	std::chrono::duration<double> printPrimesTime = t4 - t3;
	std::cout << "fillEmptyVectorTime: " << fillEmptyVectorTime.count() << std::endl;
	std::cout << "findPrimesTime: " << findPrimesTime.count() << std::endl;
	std::cout << "printPrimesTime: " << printPrimesTime.count() << std::endl;
	
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