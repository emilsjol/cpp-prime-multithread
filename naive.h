#include <vector>
#include <string>
void interpretArgument(std::string arg, bool *v, bool *t, bool *b, int *n);
void printPrimes(std::vector<bool> v);
bool isPrime(int n);
int naivePrimes(int targetNumber, int numberOfThreads, 	bool verbose, bool time);
void findPrimes(int startIndex, int endIndex, std::vector<bool> &numbers);