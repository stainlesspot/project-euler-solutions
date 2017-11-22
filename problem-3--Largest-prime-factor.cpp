#include <iostream>
#include <cmath>
#include <list>

std::list<uint64_t> knownPrimeNumbers = { 2, 3, 5 };

bool isDivisibleByKnownPrimes (uint64_t number) {
	for (
		std::list<uint64_t>::iterator it = knownPrimeNumbers.begin(), end = knownPrimeNumbers.end();
		*it <= sqrt(number) && it != end;
		++it
	)
		if (number % *it == 0)
			return true;

	return false;
}

bool findNextPrimeNumber (uint64_t limit) {
	for (uint64_t i = knownPrimeNumbers.back() + 1; i <= limit; i++)
		if(!isDivisibleByKnownPrimes(i)) {
			knownPrimeNumbers.push_back(i);
			return true;
		}

	return false;
}

int main () {
	uint64_t input;

	std::cout << "Enter your number: ";
	std::cin >> input;

	uint64_t largestPrimeFactor = input;
	uint64_t limit = input;

	for (
		std::list<uint64_t>::iterator it = knownPrimeNumbers.begin();
		*it <= limit;
		++it
	) {

		if (it == knownPrimeNumbers.end()) {
			--it;
			if (!findNextPrimeNumber(limit))
				break;
		}
		else if (limit % *it == 0) {
				largestPrimeFactor = *it;
				limit /= *it;
				--it;
			}
	}

	std::cout << "The largest prime factor of " << input << " is " << largestPrimeFactor;
	return 0;
}
