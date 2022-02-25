#include <vector>

void printPrimes(std::vector<bool> v);
bool isPrime(int n);
int naivePrimes(int targetNumber, int numberOfThreads, 	bool verbose, bool time, bool benchmark);
void findPrimes(int startIndex, int endIndex, std::vector<bool> &numbers);