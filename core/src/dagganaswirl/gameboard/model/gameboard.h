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
	void setSize(Size);
	int getPiece(const int, const int) const;
	void setPiece(int, int, int);
//	std::string toString();

private:
	Size m_size;
	int m_board; 
	/* Random rnd; */
};
