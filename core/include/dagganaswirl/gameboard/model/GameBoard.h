/* 
 * File:   GameBoard.hpp
 * Author: Miitri Raatikainen
 *
 * Created on October 11, 2012, 2:32 PM
 */

#ifndef GAMEBOARD_HPP
#define	GAMEBOARD_HPP

#include <string>

class GameBoard
{
public:
	GameBoard(GameBoard::Size);
	GameBoard::Size getSize();
	void setSize(GameBoard::Size);
	int getPiece(int, int);
	void setPiece(int, int, int);
	std::string toString();
	enum Size { SMALL = 10, MEDIUM = 15; LARGE = 20 };
private:
	GameBoard::Size size;
	int[][] board; 
	/* Random rnd; */
};

#endif	/* GAMEBOARD_HPP */
