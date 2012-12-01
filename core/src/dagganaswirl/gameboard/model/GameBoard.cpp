/*
 * File:   GameBoard.cpp
 * Author: Miitri Raatikainen
 *
 * Created on October 11, 2012, 4:45 PM
 */

#include "GameBoard.h"
#include "../../application/controllers/dagganaapp.h"
#include "../../game/model/game.h"
#include "../../common/helper/matrixhelper.h"
#include "../../selection/model/selection.h"

#include <stdlib.h>
#include <time.h>

GameBoard::GameBoard(const DagganaApp * app)
{
	GameBoard(app, MEDIUM);
}

GameBoard::GameBoard(const DagganaApp * app, GameBoard::Size size)
{
    m_app = app;
	m_size = size;
	m_board = MatrixHelper::initMatrix(size);
}

GameBoard::~GameBoard()
{
	/**
     *	Remember to delete allocated 2D array.
     */
	for (int i = 0; i < m_size; i++)
	{
		delete [] m_board[i];
	}
    delete [] m_board;
}

void GameBoard::initialize()
{
    /* initialize random seed: */
    srand ( time(NULL) );
    
    for (int i=0; i < m_size; i++)
    {
        for (int j=0; j < m_size; j++)
        {
            m_board[i][j] = rand() % (int)m_app->getGame()->getDifficulty();
        }
    }
    
}

const GameBoard::Size GameBoard::getSize() const
{
	return m_size;
}

void GameBoard::setSize(GameBoard::Size size)
{
	m_size = size;
}

int GameBoard::getPiece(const int row, const int col) const
{
	return m_board[row][col];
}

void GameBoard::setPiece(int row, int col, int value)
{
	//this->board[row][col] = value;
}

/*
GameBoard::toString()
{
	std::string ret = "";
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; this->size; j++) {
			ret += board[i][j] + " ";
		}
		ret += "\n";
	}
	return ret;
}
*/

Selection * GameBoard::createSelection(int startRow, int startCol, int endRow, int endCol)
{
	int selectionRowSize = endRow - startRow;

	// if selection is not a square
	if (selectionRowSize != (endCol - startCol)) {
		// @TODO: throw
	}

	Selection* selection = new Selection(selectionRowSize);
	
	// add all items from the selected area to the selection
	for (int row = 0; row < selectionRowSize; row++) 
	{
		for (int col = 0; col < selectionRowSize; col++) 
		{
			selection->add(m_board[row][col]);
		}
	}

	return selection;
}

void GameBoard::mergeSelection(Selection & selection)
{
	int size = selection.getRowSize();
	// point from which we start to change the values
	// @TODO: where to get these values?
	int boardRow = 0;
	int boardCol = 0;

	for (int row = 0; row < size; row++) 
	{
		for (int col = 0; col < size; col++) 
		{
			m_board[boardRow][boardCol] = selection.get(row, col);
			boardCol++;
		}
		boardRow++;
	}
}
