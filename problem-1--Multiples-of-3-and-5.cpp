#include <iostream>

uint64_t getSumOfAllMultiplesOfDivisorBellowCertainLimit (uint64_t limit, uint64_t divisor) {
	uint64_t result = 0;
	for (uint64_t number = 0; number < limit; number += divisor)
		result += number;
	return result;
}

int main () {
	uint64_t limit;
	std::cout << "Please enter the limit: ";
	std::cin >> limit;

	std::cout << "The sum of all multiples of 3 and 5 bellow " << limit << " is "
		<< getSumOfAllMultiplesOfDivisorBellowCertainLimit(limit, 3)
			+ getSumOfAllMultiplesOfDivisorBellowCertainLimit(limit, 5)
			- getSumOfAllMultiplesOfDivisorBellowCertainLimit(limit, 15);
	return 0;
}
