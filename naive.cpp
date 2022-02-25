#include "naive.h"
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <chrono>

int naivePrimes(int targetNumber, int numberOfThreads, 	bool verbose, bool time, bool benchmark) {

	int n = 0;
	int temp = 0;
	
	std::vector<std::thread> threads;
	
	std::vector<bool> numbers;
	
	std::chrono::time_point<std::chrono::steady_clock> t1, t2, t3, t4, t5;
	
	t1 = std::chrono::steady_clock::now();
	for (int i = 0; i < targetNumber; ++i) {
		numbers.push_back(0);
	}
	
	t2 = std::chrono::steady_clock::now();
	
	//thread passes by value, std::ref ensures invocability by wrapping
	for (int i = 0; i < numberOfThreads; i++) {
		threads.push_back(std::thread(findPrimes, i, numberOfThreads, std::ref(numbers)));
	}
	
	t3 = std::chrono::steady_clock::now();
	
	for (auto &th : threads) {
		th.join();
	}
	
	t4 = std::chrono::steady_clock::now();
	
	if (verbose) {
		printPrimes(numbers);
	}
	
	t5 = std::chrono::steady_clock::now();
	
	if (time) {
		std::chrono::duration<double> fillEmptyVectorTime = t2 - t1;
		std::chrono::duration<double> startThreadsTime = t3 - t2;
		std::chrono::duration<double> joinThreadsTime = t4 - t3;
		std::chrono::duration<double> printPrimesTime = t5 - t4;
		std::cout << "fillEmptyVectorTime: " << fillEmptyVectorTime.count() << std::endl;
		std::cout << "startThreadsTime: " << startThreadsTime.count() << std::endl;
		std::cout << "joinThreadsTime: " << joinThreadsTime.count() << std::endl;
		std::cout << "printPrimesTime: " << printPrimesTime.count() << std::endl;
	}
	
	return 0;
}

void findPrimes(int startIndex, int jump, std::vector<bool>& numbers) {
	
	int n = startIndex;
	int numberSize = numbers.size();
	
	while (n < numberSize) {
		
		if (isPrime(n)) {
			numbers[n] = true;
		}
		
		n = n + jump;
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