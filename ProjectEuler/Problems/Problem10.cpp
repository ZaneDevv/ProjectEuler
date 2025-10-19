#include <iostream>
#include <math.h>

#include "./Colors/Colors.h"

/**
* Exercise 10: Summation of Primes
*
* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
* Find the sum of all the primes below two million.
*
*
* @file Problem10.cpp
* @date 25/10/17
* @author Álvaro Fernández Barrero
*/



/**
* @brief Checks if a number is a prime number.
* @param Number to check.
* @return True if the given number is prime, false otherwise.
* @date 25/10/13
* @author Álvaro Fernández Barrero
*/
bool isPrime(uint64_t);



int main10()
{
	// Defining variables

	const int LIMIT = 2000000;

	uint64_t primeNumbersSum = 0;


	// Computing the sum of all prime numbers below the given limit

	for (int i = 2; i < LIMIT; i++)
	{
		if (!isPrime(i))
		{
			continue;
		}

		primeNumbersSum += i;
	}


	// Printing result

	std::cout << "The sum of all prime numbers below " << RED << LIMIT << RESET_COLOR << " is: " << BLUE << primeNumbersSum << RESET_COLOR ".\n";


	std::cin.get();
	return 0;
}



bool isPrime(uint64_t x)
{
	uint64_t n = 2;

	while (x > 0)
	{
		if (x % n == 0)
		{
			return false;
		}

		x /= n;
	}

	return true;
}