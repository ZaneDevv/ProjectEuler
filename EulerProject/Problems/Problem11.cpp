#include <iostream>
#include "./Colors/Colors.h"

/**
* Exercise 11: Largest Product in a Grid
*
* In the 20x20 grid below, four numbers along a diagonal line have been marked in red.
* 
* 08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
* 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
* 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
* 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
* 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
* 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
* 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
* 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
* 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
* 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
* 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
* 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
* 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
* 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
* 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
* 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
* 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
* 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
* 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
* 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48
* 
* The product of these numbers is 26 x 63 x 78 x 14 = 1788696.
* 
* What is the greatest product of four adjacent numbers in the same direction (up, down,
* left, right, or diagonally) in the 20x20 grid?
*
* 
* @file Problem11.cpp
* @date 25/10/17
* @author Álvaro Fernández Barrero
*/



#define GRID_SIZE 20



const int GRID[400] = {
	 8, 02, 22, 97, 38, 15, 00, 40, 00, 75, 04, 05, 07, 78, 52, 12, 50, 77, 91,  8,
	49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 04, 56, 62, 00,
	81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 03, 49, 13, 36, 65,
	52, 70, 95, 23, 04, 60, 11, 42, 69, 24, 68, 56, 01, 32, 56, 71, 37, 02, 36, 91,
	22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80,
	24, 47, 32, 60, 99, 03, 45, 02, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50,
	32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70,
	67, 26, 20, 68, 02, 62, 12, 20, 95, 63, 94, 39, 63,  8, 40, 91, 66, 49, 94, 21,
	24, 55, 58, 05, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72,
	21, 36, 23,  9, 75, 00, 76, 44, 20, 45, 35, 14, 00, 61, 33, 97, 34, 31, 33, 95,
	78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 03, 80, 04, 62, 16, 14,  9, 53, 56, 92,
	16, 39, 05, 42, 96, 35, 31, 47, 55, 58, 88, 24, 00, 17, 54, 24, 36, 29, 85, 57,
	86, 56, 00, 48, 35, 71, 89, 07, 05, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58,
	19, 80, 81, 68, 05, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 04, 89, 55, 40,
	04, 52,  8, 83, 97, 35, 99, 16, 07, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66,
	88, 36, 68, 87, 57, 62, 20, 72, 03, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69,
	04, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18,  8, 46, 29, 32, 40, 62, 76, 36,
	20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 04, 36, 16,
	20, 73, 35, 29, 78, 31, 90, 01, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 05, 54,
	01, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 01, 89, 19, 67, 48,
};



enum Direction
{
	Up,
	Down,
	Right,
	Left
};



/**
* @brief Obtains the row and column of the grid where the given index is.
* @param The index of the position in the grid.
* @param The column in the grid where the given index is.
* @param The row in the grid where the given index is.
* @date 25/10/17
* @author Álvaro Fernández Barrero
*/
void getPositionInGridByIndex(int, int&, int&);



/**
* @brief Multiplies all the numbers to the right and left to the giving coordinate.
* @param The index of the position in the grid.
* @param The column in the grid to start the multiplication.
* @param The row in the grid to start the multiplication.
* @return The greatest product of the directions, -1 if this product could not be completed.
* @date 25/10/17
* @author Álvaro Fernández Barrero
*/
int multiplyHorizontal(int, int, int);



/**
* @brief Multiplies all the numbers to the up and down to the giving coordinate.
* @param The index of the position in the grid.
* @param The column in the grid to start the multiplication.
* @param The row in the grid to start the multiplication.
* @return The greatest product of the directions, -1 if this product could not be completed.
* @date 25/10/17
* @author Álvaro Fernández Barrero
*/
int multiplyVertical(int, int, int);



/**
* @brief Multiplies all the numbers diagonally to the giving coordinate.
* @param The index of the position in the grid.
* @param The column in the grid to start the multiplication.
* @param The row in the grid to start the multiplication.
* @return The greatest product of the directions, -1 if this product could not be completed.
* @date 25/10/17
* @author Álvaro Fernández Barrero
*/
int multiplyDiagonal(int, int, int);



/**
* @brief Checks if there is at least 4 numbers in the grid in a certain direction from a point.
* @param The column where it starts checking.
* @param The row where it starts checking.
* @param The direction to check.
* @param True if there are at least 4 numbers, false otherwise.
* @date 25/10/17
* @author Álvaro Fernández Barrero
*/
bool canComputeProduct(int, int, Direction);



int main11()
{
	// Defining variables

	int column = 0;
	int row = 0;

	int greatestProduct = 0;


	// Computing the greatest product

	for (int i = 0; i < sizeof(GRID) / sizeof(*GRID); i++)
	{
		getPositionInGridByIndex(i, column, row);

		int horizontal = multiplyHorizontal(i, column, row);
		int vertical = multiplyVertical(i, column, row);
		int diagonal = multiplyDiagonal(i, column, row);

		greatestProduct = std::max(greatestProduct, std::max(std::max(horizontal, diagonal), vertical));
	}


	// Printing result

	std::cout << "The greatest product of 4 numbers in any direction in the given grid is:" << std::endl;
	std::cout << BLUE << greatestProduct << RESET_COLOR;


	std::cin.get();
	return 0;
}



void getPositionInGridByIndex(int index, int& colunm, int& row)
{
	colunm = index % GRID_SIZE;
	row = index / GRID_SIZE;
}



int multiplyHorizontal(int index, int column, int row)
{
	int productRight = 1;
	int productLeft = 1;

	for (int i = 0; i < 4; i++)
	{
		productRight *= GRID[index + i];
		productLeft *= GRID[index - i];
	}

	productRight = canComputeProduct(column, row, Right) ? productRight : -1;
	productLeft = canComputeProduct(column, row, Left) ? productLeft : -1;

	return std::max(productLeft, productRight);
}



int multiplyVertical(int index, int column, int row)
{
	int productUp = 1;
	int productDown = 1;

	for (int i = 0; i < 4; i++)
	{
		productUp *= GRID[index - i * GRID_SIZE];
		productDown *= GRID[index + i * GRID_SIZE];
	}

	productUp = canComputeProduct(column, row, Up) ? productUp : -1;
	productDown = canComputeProduct(column, row, Down) ? productDown : -1;

	return std::max(productUp, productDown);
}



int multiplyDiagonal(int index, int column, int row)
{
	int diagonalUpLeft = 1;
	int diagonalUpRight = 1;
	int diagonalDownLeft = 1;
	int diagonalDownRight = 1;

	for (int i = 0; i < 4; i++)
	{
		diagonalUpLeft *= GRID[index - i * (GRID_SIZE + 1)];
		diagonalUpRight *= GRID[index - i * (GRID_SIZE - 1)];
		diagonalDownLeft *= GRID[index + i * (GRID_SIZE + 1)];
		diagonalDownRight *= GRID[index + i * (GRID_SIZE - 1)];
	}

	diagonalUpLeft = (canComputeProduct(column, row, Up) && canComputeProduct(column, row, Left)) ? diagonalUpLeft : -1;
	diagonalUpRight = (canComputeProduct(column, row, Up) && canComputeProduct(column, row, Right)) ? diagonalUpRight : -1;
	diagonalDownLeft = (canComputeProduct(column, row, Down) && canComputeProduct(column, row, Left)) ? diagonalDownLeft : -1;
	diagonalDownRight = (canComputeProduct(column, row, Down) && canComputeProduct(column, row, Right)) ? diagonalDownRight : -1;

	return std::max(diagonalUpLeft, std::max(diagonalUpRight, std::max(diagonalDownLeft, diagonalDownRight)));
}



bool canComputeProduct(int column, int row, Direction direction)
{
	bool canCompute = false;

	switch (direction)
	{
	case Up:
		canCompute = row >= 3;
		break;

	case Down:
		canCompute = row < GRID_SIZE - 5;
		break;

	case Right:
		canCompute = column < GRID_SIZE - 5;
		break;

	case Left:
		canCompute = column >= 3;
		break;

	default:
		break;
	}

	return canCompute;
}