#include <iostream>
#include "./Colors/Colors.h"

/**
* Exercise 6: Sum Square Difference
*
* The sum of the squares of the first ten natural numbers is,
* 1^2 + 2^2 + ... + 10^2 = 385.
* 
* The square of the sum of the first ten natural numbers is,
* (1 + 2 + ... + 10)^2 = 3025
*
* Hence the difference between the sum of the squares of the first ten natural numbers
* and the square of the sum is 3025 - 385 = 3640.
* 
* Find the difference between the sum of the squares of the first one hundred natural numbers
* and the square of the sum.
* 
*
* @file Problem6.cpp
* @date 25/10/12
* @author Álvaro Fernández Barrero
*/



int main6()
{
	// Defining variables

	const uint64_t SUM_MEMBERS_AMOUNT = 100;

	size_t sumOfSquares = 0;
	size_t squareOfSums = 0;


	// Computing the operations for the firsts natural numbers
	
	for (uint64_t i = 1; i <= SUM_MEMBERS_AMOUNT; i++)
	{
		sumOfSquares += i * i;
		squareOfSums += i;
	}
	squareOfSums *= squareOfSums;


	// Printing result:

	std::cout << "The result of the sum of the first " << GREEN << SUM_MEMBERS_AMOUNT << RESET_COLOR << " squares is:\n";
	std::cout << BLUE << "1^2 + 2^2 + 3^2 + ... + " << SUM_MEMBERS_AMOUNT - 1 << "^2 + " << SUM_MEMBERS_AMOUNT << "^2 = " << sumOfSquares << RESET_COLOR;

	std::cout << "\n\nThe result of the sum of the first " << GREEN << SUM_MEMBERS_AMOUNT << RESET_COLOR << " natural square is:\n";
	std::cout << BLUE << "(1 + 2 + 3 + ... + " << SUM_MEMBERS_AMOUNT - 1 << " + " << SUM_MEMBERS_AMOUNT << ")^2 = " << squareOfSums << RESET_COLOR;

	std::cout << "\n\nTherefore, the difference between the sum of the squares of the first "
		GREEN << SUM_MEMBERS_AMOUNT << RESET_COLOR << " natural numbers and the square of the sum is:\n";
	std::cout << BLUE << squareOfSums << " - " << sumOfSquares << " = " << (squareOfSums - sumOfSquares) << RESET_COLOR << ".\n";


	std::cin.get();
	return 0;
}