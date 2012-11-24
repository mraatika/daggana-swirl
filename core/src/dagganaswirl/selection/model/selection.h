/*
 * selection.h
 *
 *  Created on: 13.10.2012
 *      Author: mraatika
 */

#ifndef SELECTION_H_
#define SELECTION_H_

class Selection
{
public:
	Selection(int rowSize);
	virtual ~Selection();

	enum ActionType
	{
		CLOCKWISE,
		COUNTER_CLOCKWISE,
		MIRROR_HORIZONTALLY,
		MIRROR_VERTICALLY,
		MIRROR_BOTH,
		SHUFFLE
	};

	/*
	 *  Returns the size of the whole selection matrix (rowSize * rowSize).
	 *
	 *  @return {int} matrix size
	 */
	int getSize();

	/**
	 *  Returns the size of a row.
	 *
	 *  @return {int} row size
	 */
	int getRowSize();
	
	/**
	 *  Add a piece to the selection
	 *
	 *  @param {int} size
	 */
	void add(int piece);

	/**
	 *  Get a piece from the selection
	 *
	 *  @param {int} row Row index
	 *  @param {int} col Column index
	 */
	int get(int row, int col);

	/**
	 * Alters the selection as defined by the action parameter
	 *
	 * @param {ActionType} action The type of the action to perform
	 *
	 */
	void doAction(ActionType action);

	/**
	 *  Debug function to print representation of the selection to the console.
	 *
	 */
	void printOut();

private:
	int** m_container;
	int m_size;
	int m_latestRow;
	int m_latestCol;

	void turnCClockWise();
	void turnClockWise();
	void mirrorHorizontally();
	void mirrorVertically();
	void shuffle();

	/**
	 * Swap the places of two pieces
	 *
	 * @param {int} startRow from which row
	 * @param {int} startCol from which column
	 * @param {int} endRow to which row
	 * @param {int} endCol to which colum
	 */
	void swap(int startRow, int startCol, int endRow, int endCol);
};

#endif /* SELECTION_H_ */
