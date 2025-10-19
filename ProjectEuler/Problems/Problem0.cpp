#include <iostream>
#include "./Colors/Colors.h"

/**
* Exercise 0: Problem Zero
*
* A number is a perfect square, or a square number, if it is the square of a positive integer.
* For example, 25 is a square number because 5^2 = 5x5 = 25; it is also an odd square.
*
* The first 5 square numbers are: 1, 4, 9, 16, 25, and the sum of the odd squares is 1 + 9 + 25 = 35.
*
* Among the first 397 thousand square numbers, what is the sum of all the odd squares?
*
*
* @file Problem0.cpp
* @date 25/10/19
* @author Álvaro Fernández Barrero
*/



/**
* @brief Checks if the given number is odd.
* @param The number to check.
* @return True if the given number is odd, false otherwise.
* @date 25/10/19
* @author Álvaro Fernández Barrero
*/
inline bool isOdd(uint64_t);



int main0()
{
	// Defining variables

	const uint64_t ODD_SQUARE_NUMBERS_AMOUNT = 397;

	uint64_t result = 0;

	uint64_t i = 0;
	uint64_t n = 1;


	// Computing the sum of the first 397 odd square numbers

	while (++i < ODD_SQUARE_NUMBERS_AMOUNT)
	{
		n++;
		uint64_t squareNumber = n * n;

		if (!isOdd(squareNumber))
		{
			continue;
		}

		result += squareNumber;
	}


	// Printing result

	std::cout << "The sum of the first " << RED << ODD_SQUARE_NUMBERS_AMOUNT << RESET_COLOR << " odd square numbers is " << BLUE << result << RESET_COLOR << ".\n";


	std::cin.get();
	return 0;
}



inline bool isOdd(uint64_t x)
{
	return x % 2 > 0;
}