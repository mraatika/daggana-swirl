/* 
 * File:   GameBoard.hpp
 * Author: Miitri Raatikainen
 *
 * Created on October 11, 2012, 2:32 PM
 */

#pragma once

//#include <string>

class GameBoard
{
public:
	enum Size
	{ 
		SMALL = 10, 
		MEDIUM = 15, 
		LARGE = 20
	};
	
	GameBoard();
	GameBoard(Size);
	const Size getSize() const;
	void setSize(Size size);
	int getPiece(const int row, const int col) const;
	void setPiece(int row, int col, int value);
//	std::string toString();

private:
	Size m_size;
	int m_board; 
	/* Random rnd; */
};
