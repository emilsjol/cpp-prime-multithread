#include <iostream>
#include <string>

int main(int argc, char **argv) {
	
	int targetNumber;
	int n = 1;
	int temp = 0;
	bool foundPrime;
	
	if (argc == 0) {
		targetNumber = 100;
	} else {
		targetNumber = std::stoi(argv[1]);
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
			std::cout << n << std::endl;
		}
		
		n++;
	}
	
	return 0;
}