#include <iostream>

uint64_t fib (uint32_t position) {
	if (position == 1)
		return 1;
	if (position == 2)
		return 2;
	return fib(position - 1) + fib(position - 2);
}

int main () {
	const uint64_t LIMIT = 4000000;
	uint64_t sum = 0;

	for (
		uint32_t fib = 1, previousFib = 1;
		fib <= LIMIT;
		fib += previousFib, previousFib = fib - previousFib
	)
		if (fib % 2 == 0)
			sum += fib;

	std::cout << "The sum of all even Fibonacci numbers, who do not exceed 4 million is " << sum;
	return 0;
}
