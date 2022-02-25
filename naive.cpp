#include "naive.h"
#include <iostream>
#include <string>

int findPrimes(int targetNumber) {

	int n = 1;
	int temp = 0;
	bool foundPrime;
	
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
			std::cout << n << std::endl;
		}
		
		n++;
	}
	
	return 0;
}