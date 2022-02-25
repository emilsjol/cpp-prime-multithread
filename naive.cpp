#include "naive.h"
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <chrono>

int naivePrimes(int targetNumber, int numberOfThreads) {

	int n = 0;
	int temp = 0;
	
	std::vector<std::thread> threads;
	
	std::vector<bool> numbers;
	
	std::chrono::time_point<std::chrono::steady_clock> t1, t2, t3, t4;
	
	t1 = std::chrono::steady_clock::now();
	for (int i = 0; i < targetNumber; ++i) {
		numbers.push_back(0);
	}
	
	t2 = std::chrono::steady_clock::now();
	
	findPrimes(0, targetNumber, numbers);
	
	t3 = std::chrono::steady_clock::now();
	
	printPrimes(numbers);
	t4 = std::chrono::steady_clock::now();
	
	std::chrono::duration<double> fillEmptyVectorTime = t2 - t1;
	std::chrono::duration<double> findPrimesTime = t3 - t2;
	std::chrono::duration<double> printPrimesTime = t4 - t3;
	std::cout << "fillEmptyVectorTime: " << fillEmptyVectorTime.count() << std::endl;
	std::cout << "findPrimesTime: " << findPrimesTime.count() << std::endl;
	std::cout << "printPrimesTime: " << printPrimesTime.count() << std::endl;
	
	return 0;
}

void findPrimes(int startIndex, int endIndex, std::vector<bool> &numbers) {
	
	int n = startIndex;
	
	while (n < endIndex) {
		
		if (isPrime(n)) {
			numbers[n] = true;
		}
		
		n++;
	}
	
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
		if (v[i] == true) {
			std::cout << i << std::endl;
		}
	}
}