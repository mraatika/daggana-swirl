/*
 * selection.cpp
 *
 *  Created on: 13.10.2012
 *      Author: mraatika
 */

#include "selection.h"
#include "../../common/helper/matrixhelper.cpp"
#include <math.h>
#include <stdlib.h>
#include <time.h>

Selection::Selection(int** selection)
{
	m_container = selection;
}

Selection::~Selection()
{
	// TODO: delete each selection row
}

int Selection::getSize()
{
	return sizeof m_container[0] / sizeof(int);
}

int Selection::getPiece(int row, int col)
{
	return m_container[row][col];
}

void Selection::doAction(ActionType action)
{
	switch (action)
	{
	case CLOCKWISE:
		turnClockWise();
		break;
	case COUNTER_CLOCKWISE:
		turnCClockWise();
		break;
	case MIRROR_HORIZONTALLY:
		mirrorHorizontally();
		break;
	case MIRROR_VERTICALLY:
		mirrorVertically();
		break;
	case MIRROR_BOTH:
		mirrorHorizontally();
		mirrorVertically();
		break;
	case SHUFFLE:
		shuffle();
		break;
	}
}

void Selection::turnClockWise()
{
	int rowSize = getSize();
	int** newArray = MatrixHelper::initMatrix(rowSize);

	for (int i = (rowSize - 1); i >= 0; --i) {
		for (int j = 0; j < rowSize; ++j) {
			newArray[(rowSize - 1) - j][i] = getPiece(i, j);
		}
	}
	m_container = newArray;
}


void Selection::turnCClockWise()
{
	int rowSize = getSize();
	int** newArray = MatrixHelper::initMatrix(rowSize);

	for (int i = (rowSize - 1); i >= 0; --i) {
		for (int j = 0; j < rowSize; ++j) {
			newArray[j][(rowSize - 1)- i] = getPiece(i, j);
		}
	}

	m_container = newArray;
}

void Selection::mirrorHorizontally()
{
	int rowSize = getSize();
	int half = (int) floor(rowSize / 2);

	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < half; j++) {
			swap(i, i, j, rowSize - (j + 1));
		}
	}
}

void Selection::mirrorVertically()
{
	int rowSize = getSize();
	int half = (int) floor(rowSize / 2);

	for (int i = 0; i < half; i++) {
		for (int j = 0; j < rowSize; j++) {
			swap(i, rowSize - (i + 1), j, j);
		}
	}
}

void Selection::shuffle()
{
	srand(time(NULL));

	int rowSize = getSize();

	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < rowSize; j++) {
			int rnd1 = (int) rand() % rowSize;
			int rnd2 = (int) rand() % rowSize;

			swap(i, rnd1, j, rnd2);
		}
	}
}

void Selection::swap(int startRow, int startCol, int endRow, int endCol)
{
	int temp = getPiece(startRow, startCol);
	m_container[startRow][startCol] = getPiece(endRow, endCol);
	m_container[endRow][endCol] = temp;
}
