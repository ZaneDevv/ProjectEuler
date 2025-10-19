#include <iostream>
#include "./Colors/Colors.h"

/**
* Exercise 5: Smallest Multiple
*
* 2520 is the smallest number that can be divided by each of the numbers
* from 1 to 5 without any remainder.
* 
* What is the smallest positive number that is evenly divisible by all
* of the numbers from 1 to 20?
*
*
* @file Problem5.cpp
* @date 25/10/12
* @author Álvaro Fernández Barrero
*/


/**
* @brief Checks if the given numbers is divisible by another.
* @param The number to check.
* @param The divisible number.
* @return True if it is divisible by the other, false otherwhise.
* @date 25/10/12
* @author Álvaro Fernández Barrero
*/
bool isDivisibleByAllNumbersBelow(size_t, size_t);



int main5()
{
	// Defining variables.

	const uint64_t GREATEST_NUMBER_TO_BE_DISIVIBLE = 20;
	uint64_t smallest = 2520;


	// Obtaining the result.

	while (!isDivisibleByAllNumbersBelow(smallest, GREATEST_NUMBER_TO_BE_DISIVIBLE))
	{
		smallest += GREATEST_NUMBER_TO_BE_DISIVIBLE;
	}

	
	// Printing result

	std::cout << "The smallest positive number that is divisible by all numbers " << GREEN << "from 1 to 20" << RESET_COLOR << " is ";
	std::cout << BLUE << smallest << RESET_COLOR << ".\n";


	std::cin.get();
	return 0;
}



bool isDivisibleByAllNumbersBelow(size_t x, size_t max)
{
	for (uint64_t i = 2; i <= max; i++)
	{
		if (x % i > 0)
		{
			return false;
		}
	}

	return true;
}