/*
 * File:   GameBoard.cpp
 * Author: Miitri Raatikainen
 *
 * Created on October 11, 2012, 4:45 PM
 */

#include "GameBoard.h"

GameBoard::GameBoard()
{

}

GameBoard::GameBoard(GameBoard::Size size)
{
	m_size = size;
	//this->board = int[size][size];
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
	// return this->board[row][col];
	return 1;
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