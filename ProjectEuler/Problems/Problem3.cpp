#include <iostream>
#include "./Colors/Colors.h"

/**
* Exercise 3: Largest Prime Factor
*
* The prime factors of 13195 are 5, 7, 13 and 29.
* What is the largest prime factor of the number 600851475143?
*
*
* @file Problem3.cpp
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
inline bool isDivisible(size_t, size_t);



int main3()
{
	// Defining variables.

	const size_t originalNumber = 600851475143;
	size_t number = 600851475143;

	size_t divisionFactor = 2;

	size_t greatesPrime = 0;


	// Checking the greatest prime factor of the number.

	while (number > 1)
	{
		if (isDivisible(number, divisionFactor))
		{
			greatesPrime = divisionFactor;

			while (isDivisible(number, divisionFactor))
			{
				number /= divisionFactor;
			}
		}

		divisionFactor++;
	}


	// Printing the result.

	std::cout << "The greates prime factor of the number " << GREEN << originalNumber << RESET_COLOR << " is ";
	std::cout << BLUE << greatesPrime << RESET_COLOR << ".\n";


	std::cin.get();
	return 0;
}



inline bool isDivisible(size_t x, size_t divisible)
{
	return x % divisible == 0;
}