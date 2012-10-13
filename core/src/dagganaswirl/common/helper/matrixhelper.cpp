
/*
 * matrixhelper.cpp
 *
 *  Created on: 13.10.2012
 *      Author: mraatika
 */

#include "matrixhelper.h"

MatrixHelper::MatrixHelper() {}

int** MatrixHelper::initMatrix(int size)
{
	int** matrix = new int*[size];

	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}

	return matrix;
}
