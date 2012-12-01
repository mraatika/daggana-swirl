/*
 * selection.cpp
 *
 *  Created on: 13.10.2012
 *      Author: mraatika
 */

#include "selection.h"
#include "../../common/helper/matrixhelper.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

Selection::Selection(int rowSize)
{
	m_size = rowSize;
	m_latestCol = 0;
	m_latestRow = 0;
	m_container = MatrixHelper::initMatrix(rowSize);
}

Selection::~Selection()
{
	resetContainer(NULL);
}

int Selection::getSize()
{
	return m_size * m_size;
}

int Selection::getRowSize()
{
	return m_size;
}

void Selection::add(int piece)
{
	if (m_latestRow >= m_size) {
		return;
	}

	m_container[m_latestRow][m_latestCol] = piece;

	if (m_latestCol == m_size -1) {
		m_latestCol = 0;
		m_latestRow++;
	} else {
		m_latestCol++;
	}
}

int Selection::get(int row, int col)
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

void Selection::turnCClockWise()
{
	int rowSize = getRowSize();
	int** newArray = MatrixHelper::initMatrix(rowSize);

	for (int i = (rowSize - 1); i >= 0; --i) {
		for (int j = 0; j < rowSize; ++j) {
			newArray[(rowSize - 1) - j][i] = get(i, j);
		}
	}
	
	resetContainer(newArray);
}


void Selection::turnClockWise()
{
	int rowSize = getRowSize();
	int** newArray = MatrixHelper::initMatrix(rowSize);

	for (int i = (rowSize - 1); i >= 0; --i) {
		for (int j = 0; j < rowSize; ++j) {
			newArray[j][(rowSize - 1)- i] = get(i, j);
		}
	}

	resetContainer(newArray);
}

void Selection::mirrorHorizontally()
{
	int rowSize = getRowSize();
	int half = (int) std::floor((double) rowSize / 2);

	// iterate all the columns
	for (int col = 0; col < rowSize; col++) {
		// iterate half of the rows
		for (int row = 0; row < half; row++) {
			// swap item from "top" row to "bottom" and vice versa
			swap(row, col, rowSize - (row + 1), col);
		}
	}
}

void Selection::mirrorVertically()
{
	int rowSize = getRowSize();
	int half = (int) std::floor((double) rowSize / 2);

	// iterate half of the columns
	for (int col = 0; col < half; col++) {
		// iterate all the rows
		for (int row = 0; row < rowSize; row++) {
			// swap item from the left column to the right column and vice versa
			swap(row, col, row, rowSize - (col + 1));
		}
	}	
}

void Selection::shuffle()
{
	srand(time(NULL));

	int rowSize = getRowSize();

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
	// memorize the end point's value
	int temp = get(startRow, startCol);
	// set start point's value to the end point
	m_container[startRow][startCol] = get(endRow, endCol);
	// set memorized value to the start point
	m_container[endRow][endCol] = temp;
}

void Selection::resetContainer(int** newArray) 
{
	int size = getRowSize();

	/**
     *	Remember to delete allocated 2D array.
     */
	for (int i = 0; i < m_size; i++)
	{
		delete [] m_container[i];
	}
    delete [] m_container;

	// newArray becomes selection's current state
	m_container = newArray;
}

void Selection::printOut() 
{
	int size = getRowSize();

	for (int i = 0; i < size; i++) 
	{
		int* row = m_container[i];

		for (int j = 0; j < size; j++) 
		{
			std::cout << row[j] << ((row[j] < 10) ? "  " : " ");
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}
