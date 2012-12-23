/* 
 * File:   GameBoard.hpp
 * Author: Miitri Raatikainen
 *
 * Created on October 11, 2012, 2:32 PM
 */

#pragma once

class DagganaApp;
class Selection;
class Coordinate;

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

	/**
	 *  Set piece to board.
	 *
	 *  @param {int} row
	 *  @param {int} col
	 *
	 */
	int getPiece(const int row, const int col) const;
	
	/**
	 *  Set piece to board.
	 *
	 *  @param {int} row
	 *  @param {int} col
	 *  @param {int} value
	 *
	 */
	void setPiece(const int row, const int col, const int value);

	/**
	 *  Merges selection back to the gameboard.
	 *
	 *  @param {Selection} selection
	 *
	 */
	void mergeSelection(Selection * selection, Coordinate start);

	/**
	 *  Creates a new selection from a part of the gameboard.
	 *
	 */
	Selection * createSelection(Coordinate start, Coordinate end);

	/**
	 *  Prints the out the textual representation of the board
	 *
	 */
	void printOut();

private:
	/**
     *  The size of the board's one side
     */
	Size m_size;
	int** m_board;
	const DagganaApp * m_app;

	/**
	 *  Current selection's starting coordinate 
	 */
	Coordinate * m_selectionStart;	
};
