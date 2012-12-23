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
#include "../../common/model/coordinate.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

GameBoard::GameBoard(const DagganaApp * app)
{
	GameBoard(app, MEDIUM);
}

GameBoard::GameBoard(const DagganaApp * app, GameBoard::Size size)
{
    m_app = app;
	m_size = size;
	m_board = MatrixHelper::initMatrix(size);
	// @FIXME: hard coded default
	m_selectionStart = new Coordinate(1, 1);
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
	delete m_selectionStart;
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
	m_board[row][col] = value;
}

void GameBoard::printOut()
{
	int size = m_size;

	for (int i = 0; i < size; i++) 
	{
		int* row = m_board[i];

		for (int j = 0; j < size; j++) 
		{
			std::cout << row[j] << ((row[j] < 10) ? "   " : (row[j] < 100) ? "  ": " ");
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

Selection * GameBoard::createSelection(Coordinate start, Coordinate end)
{
	int selectionRowSize = end.getY() - start.getY();

	// if selection's column is outside bounds
	if (start.getX() < 0 || end.getX() >= getSize()) 
	{
		// @TODO: throw
	}

	// if selection's row is outside bounds
	if (start.getY() < 0 || end.getY() >= getSize()) 
	{
		// @TODO: throw
	}

	// if selection is not a square
	if (selectionRowSize != (end.getX() - end.getX())) 
	{
		// @TODO: throw
	}

	Selection* selection = new Selection(selectionRowSize + 1);

	// top left point from which we start to change the values
	int boardRow = start.getY();
	int boardCol = start.getX();
	
	// add all items from the selected area to the selection
	for (int row = 0; row < selectionRowSize + 1; row++) 
	{
		for (int col = 0; col < selectionRowSize + 1; col++) 
		{
			int piece = m_board[boardRow + row][boardCol + col];
			selection->add(piece);
		}
	}

	return selection;
}

void GameBoard::mergeSelection(Selection * selection, Coordinate start)
{
	int size = selection->getRowSize();
	// top left point from which we start to change the values
	int boardRow = start.getY();
	int boardCol = start.getX();

	for (int row = 0; row < size; row++) 
	{
		for (int col = 0; col < size; col++) 
		{
			m_board[boardRow + row][boardCol + col] = selection->get(row, col);
		}
	}
}
