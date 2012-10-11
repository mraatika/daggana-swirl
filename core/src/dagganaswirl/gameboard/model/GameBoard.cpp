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
	this->size = size;
	this->board = int[size][size];
}

GameBoard::getSize()
{
	return this->size;
}

GameBoard::setSize(GameBoard::Size size)
{
	this->size = size;
}

GameBoard::getPiece(int row, int col)
{
	return this->board[row][col];
}

GameBoard::setPiece(int row, int col, int value)
{
	this->board[row][col] = value;
}

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