#include <iostream>
#include <set>

#include "./Colors/Colors.h"

/**
* Exercise 1: Multiples of 3 or 5
* 
* If we list all the natural numbers below 10 that are multiples of 3 or 5,
* we get 3, 5, 6 and 9. The sum of these multiples is 23.
* 
* Find the sum of all the multiples of 3 or 5 below 1000.
* 
* 
* @file Problem1.cpp
* @date 25/10/12
* @author Álvaro Fernández Barrero
*/



int main1()
{
	// Defining variables.

	std::set<int>  multiples;
	const int MAXIMUM = 1000;

	int totalSum = 0;


	// Saving the multiples of 5.

	for (int i = 5; i <= MAXIMUM; i += 5)
	{
		multiples.insert(i);
	}


	// Saving the multiples of 5.

	for (int i = 3; i <= MAXIMUM; i += 3)
	{
		multiples.insert(i);
	}

	
	// Adding up all multiples

	for (int x : multiples)
	{
		totalSum += x;
	}


	// Printing the result.

	std::cout << "The sum of all numbers that are multiples of either " 
		<< GREEN << 3 << RESET_COLOR << " or " << GREEN << 5 << RESET_COLOR 
		<< " and less that " << RED << MAXIMUM << RESET_COLOR 
		<< " is ";
	std::cout << BLUE << totalSum << RESET_COLOR << ".\n";


	std::cin.get();
	return 0;
}