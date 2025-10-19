#include <iostream>
#include "./Colors/Colors.h"

/**
* Exercise 4: Largest Palindrome Product
*
* A palindromic number reads the same both ways. The largest palindrome made from the
* product of two 2-digit numbers is 9009 = 91 x 99.
*
* Find the largest palindrome made from the product of two 3-digit numbers.
* 
*
* @file Problem4.cpp
* @date 25/10/12
* @author Álvaro Fernández Barrero
*/



typedef unsigned char ubyte_t;



/**
* @brief Checks if the given numbers is a palindrome.
* @param The number to check.
* @return True if it is a palindrome, false otherwhise.
* @date 25/10/12
* @author Álvaro Fernández Barrero
*/
bool isNumberAPalindrome(uint64_t);



int main4()
{
	// Defining variables.

	uint64_t largestPalindrome = 0;


	// Checking divisions results are palindromes.

	for (uint64_t i = 999; i >= 500; --i)
	{
		for (uint64_t j = 999; j >= 500; --j)
		{
			uint64_t ij = i * j;

			if (!isNumberAPalindrome(ij))
			{
				continue;
			}

			largestPalindrome = ij;
			break;
		}
	}


	// Printing result.

	std::cout << "The largest palindrome number that is also thr result of the multiplication of two "
		<< GREEN << "3-digits" << RESET_COLOR << " number is ";
	std::cout << BLUE << largestPalindrome << RESET_COLOR << ".\n";


	std::cin.get();
	return 0;
}



bool isNumberAPalindrome(uint64_t x)
{
	uint64_t reversed = 0;
	uint64_t original = x;

	while (x > 0)
	{
		reversed = reversed * 10 + x % 10;
		x /= 10;
	}

	return original == reversed;
}