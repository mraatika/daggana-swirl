/*
 * File:   GameBoard.cpp
 * Author: Miitri Raatikainen
 *
 * Created on October 11, 2012, 4:45 PM
 */

#include "GameBoard.h"
#include "../../application/controllers/dagganaapp.h"
#include "../../game/model/game.h"

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
	m_board = new int *[size];
    
    for (int i=0; i < size; i++)
    {
        m_board[i] = new int[size];
    }
    
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
