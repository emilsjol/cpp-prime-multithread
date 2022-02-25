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
	
	std::chrono::time_point<std::chrono::steady_clock> t1, t2, t3, t4, t5;
	
	t1 = std::chrono::steady_clock::now();
	for (int i = 0; i < targetNumber; ++i) {
		numbers.push_back(0);
	}
	
	t2 = std::chrono::steady_clock::now();
	
	//thread passes by value, std::ref ensures invocability by wrapping
	std::thread thr1(findPrimes, 0, targetNumber/2, std::ref(numbers));
	std::thread thr2(findPrimes, targetNumber/2, targetNumber, std::ref(numbers));
	
	t3 = std::chrono::steady_clock::now();
	
	
	thr1.join();
	thr2.join();
	
	t4 = std::chrono::steady_clock::now();
	
	printPrimes(numbers);
	
	t5 = std::chrono::steady_clock::now();
	
	
	std::chrono::duration<double> fillEmptyVectorTime = t2 - t1;
	std::chrono::duration<double> startThreadsTime = t3 - t2;
	std::chrono::duration<double> joinThreadsTime = t4 - t3;
	std::chrono::duration<double> printPrimesTime = t5 - t4;
	std::cout << "fillEmptyVectorTime: " << fillEmptyVectorTime.count() << std::endl;
	std::cout << "startThreadsTime: " << startThreadsTime.count() << std::endl;
	std::cout << "joinThreadsTime: " << joinThreadsTime.count() << std::endl;
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