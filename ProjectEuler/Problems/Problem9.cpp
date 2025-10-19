#include <iostream>
#include <math.h>

#include "./Colors/Colors.h"

/**
* Exercise 9: Special Pythagorean Triplet
*
* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, 
* a^2 + b^2 = c^2
*
* For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
* 
* There exists exactly one Pythagorean triplet for which a + b + c = 1000.
* Find the product abc.
* 
*
* @file Problem9.cpp
* @date 25/10/17
* @author Álvaro Fernández Barrero
*/



/**
* @brief Checks if the given number is an integer.
* @param Number to check if it is an integer.
* @return True if the number has no decimals, false otherwise.
* @date 25/10/17
* @author Álvaro Fernández Barrero
*/
bool isInteger(double);



/**
* @brief Checks if the three given numbers make a Pythagorean triplet.
* @param First integer for the triplet.
* @param Second integer for the triplet.
* @param Third integer for the triplet.
* @return True if the 3 numbers make a Pythagoren triplet, false otherwise.
* @date 25/10/17
* @author Álvaro Fernández Barrero
*/
bool isTriplet(int, int, int);



/**
* @brief Computes the third number for the Pythagorean triplet.
* @param First integer for the triplet.
* @param Second integer for the triplet.
* @return The third number to make the triplet.
* @date 25/10/17
* @author Álvaro Fernández Barrero
*/
double computeC(int, int);



int main9()
{
	// Defining variables

	const int tripletSum = 1000;

	int a = 0;
	int b = 0;
	int c = 0;


	// Computing a, b and c

	for (int i = 1; i < tripletSum; ++i)
	{
		for (int j = 1; j < tripletSum; ++j)
		{
			double k = computeC(i, j);

			if (!isInteger(k))
			{
				continue;
			}

			if (!isTriplet(i, j, (int)k))
			{
				continue;
			}

			if (i + j + k != tripletSum)
			{
				continue;
			}

			a = i;
			b = j;
			c = (int)k;

			break;
		}
	}


	// Printing the result

	std::cout << a << "^2 + " << b << "^2 = " << c << "^2" << std::endl;
	std::cout << a << " + " << b << " + " << c << " = " << BLUE << (a + b + c) << RESET_COLOR << std::endl;
	std::cout << a << " x " << b << " x " << c << " = " << BLUE << (a * b * c) << RESET_COLOR;


	std::cin.get();
	return 0;
}



bool isInteger(double x)
{
	return x == (int)x;
}



bool isTriplet(int a, int b, int c)
{
	return a * a + b * b == c * c;
}



double computeC(int a, int b)
{
	return sqrt(a * a + b * b);
}
