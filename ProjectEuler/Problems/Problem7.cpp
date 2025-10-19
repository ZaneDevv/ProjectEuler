#include <iostream>
#include <cmath>

#include "./Colors/Colors.h"

/**
* Exercise 7: 10,001st Prime
*
* By listing the first six prime numbers: 2, 3, 5, 7, 11 and 13, we can see that the 6th prime is 13.
* What is the 10,001st prime number?
*
* @file Problem7.cpp
* @date 25/10/12
* @author Álvaro Fernández Barrero
*/


typedef unsigned long long ulong_t;



/**
* @brief Checks if the given number is a primer number
* @param The number to check whether is prime or not.
* @return True if the given number is prime, false otherwise.
* @date 25/10/12
* @author Álvaro Fernández Barrero
*/
bool isPrimeNumber(uint64_t);



/**
* @brief Checks if the given number is a divisible by another one.
* @param The number to check if is divisible by the other one.
* @param The divisible number.
* @return True if the given number is divisible by the other, false otherwise.
* @date 25/10/12
* @author Álvaro Fernández Barrero
*/
inline bool isDividibleBy(uint64_t, uint64_t);



int main7()
{
	// Defining variables

	const uint64_t PRIME_NUMBER = 10001;

	uint64_t currentPrimeNumber = 0;
	ulong_t n = 0;

	ulong_t result = 0;


	// Computing the 10,001st prime number

	do
	{
		n++;

		if (isPrimeNumber(n))
		{
			currentPrimeNumber++;
			result = n;
		}


	} while (currentPrimeNumber < PRIME_NUMBER);


	// Printint result

	std::cout << "The " << RED << "10,001st" << RESET_COLOR << " prime number is " << BLUE << result << RESET_COLOR << ".\n";


	std::cin.get();
	return 0;
}



bool isPrimeNumber(uint64_t x)
{
	for (uint64_t i = 2; i < sqrt(x); i++)
	{
		if (!isDividibleBy(x, i))
		{
			continue;
		}

		return false;
	}

	return true;
}



inline bool isDividibleBy(uint64_t x, uint64_t y)
{
	return x % y == 0;
}