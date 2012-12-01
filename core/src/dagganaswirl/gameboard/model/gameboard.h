/* 
 * File:   GameBoard.hpp
 * Author: Miitri Raatikainen
 *
 * Created on October 11, 2012, 2:32 PM
 */

#pragma once

class DagganaApp;
class Selection;

class GameBoard
{
public:
	enum Size
	{ 
		SMALL = 10, 
		MEDIUM = 15, 
		LARGE = 20
	};

	GameBoard(const DagganaApp * app);
	GameBoard(const DagganaApp * app, Size);
    ~GameBoard();
    
    void initialize();
	const Size getSize() const;
	void setSize(Size size);
	int getPiece(const int row, const int col) const;
	void setPiece(int row, int col, int value);

private:
	Size m_size;
	int** m_board;
	const DagganaApp * m_app;

	/**
	 *  Creates a new selection from a part of the gameboard.
	 *
	 */
	Selection * createSelection(int startRow, int startCol, int endRow, int endCol);

	/**
	 *  Merges selection back to the gameboard.
	 *
	 *  @param {Selection} selection
	 *
	 */
	void mergeSelection(Selection & selection);
};
