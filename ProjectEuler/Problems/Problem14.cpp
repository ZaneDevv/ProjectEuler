#include <iostream>
#include "./Colors/Colors.h"

/**
* Exercise 14: Longest Collatz Sequence
*
* The following iterative sequence is defined for the set of positive integers:
* 
* n -> n/2 (n is even)
* n -> 3n+1 (n is odd)
* 
* Using the rule above and starting with 13, we generate the following sequence:
* 
* 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
* 
* It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has
* not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
* 
* Which starting number, under one million, produces the longest chain?
* 
* NOTE: Once the chain starts the terms are allowed to go above one million.
*
* 
* @file Problem14.cpp
* @date 25/10/18
* @author Álvaro Fernández Barrero
*/



/**
* @brief Checks if the given number is even.
* @param The number to check.
* @return True if the given number is even, false if it is odd.
* @date 25/10/17
* @author Álvaro Fernández Barrero
*/
inline bool isNumberEven(uint64_t);



/**
* @brief Computes the amount of numbers that are in the given number's Collarz sequence.
* @param The number to check its Collatz sequence.
* @return The amount of numbers in the given number's Collarz sequence.
* @date 25/10/17
* @author Álvaro Fernández Barrero
*/
size_t getAmountOfNumbersInCollatzSequence(uint64_t);



int main14()
{
	// Defining variables

	const uint64_t LIMIT = 1000000;

	uint64_t numberLongestCollatzSequence = 1;
	size_t sequenceMembersAmount = 0;


	// Computing the number below to one million with the longest Collatz sequence

	for (uint64_t i = 1; i < LIMIT; ++i)
	{
		size_t amountNumbersInCollatzSequence = getAmountOfNumbersInCollatzSequence(i);

		if (amountNumbersInCollatzSequence > sequenceMembersAmount)
		{
			numberLongestCollatzSequence = i;
			sequenceMembersAmount = amountNumbersInCollatzSequence;
		}
	}


	// Printing result

	std::cout << "The number below to " << RED << LIMIT << RESET_COLOR << " with the longest Collatz sequence is ";
	std::cout << BLUE << numberLongestCollatzSequence << RESET_COLOR << " with " << BLUE << sequenceMembersAmount << RESET_COLOR;
	std::cout << " numbers in its sequence.";


	std::cin.get();
	return 0;
}



inline bool isNumberEven(uint64_t x)
{
	return x % 2 == 0;
}


size_t getAmountOfNumbersInCollatzSequence(uint64_t x)
{
	size_t result = 0;

	while (x > 1)
	{
		x = isNumberEven(x) ? (x / 2) : (3 * x + 1);
		result++;
	}

	return result;
}