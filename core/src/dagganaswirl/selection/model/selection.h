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
	/**
	 *  @constructor
	 *  @param {int} rowSize
	 *
	 */
	Selection(int rowSize);
	virtual ~Selection();

	/**
	 *  All the possible actions for a selection class.
	 *
	 */
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
	// properties

	// container for the items in this selection
	int** m_container;
	// selection's item count
	int m_size;
	// memorized value of the latest row that 
	// a value was inserted into.
	int m_latestRow;
	// memorized value of the latest column that 
	// a value was inserted into.
	int m_latestCol;
	
	// actions

	/**
	 *  Rotates the selection so that the top left 
	 *  corner becomes the bottom left corner and so on.
	 */
	void turnCClockWise();
	/**
	 *  Rotates the selection so that the top left 
	 *  corner becomes top right corner and so on.
	 */
	void turnClockWise();
	/**
	 *  Mirrors the selection around it's horizontal axel.
	 */
	void mirrorHorizontally();
	/**
	 *  Mirrors the selection around it's vertical axel.
	 */
	void mirrorVertically();
	/**
	 *  Shuffles the selections values
	 */
	void shuffle();

	// Others

	/**
	 * Swap the places of two pieces
	 *
	 * @param {int} startRow from which row
	 * @param {int} startCol from which column
	 * @param {int} endRow to which row
	 * @param {int} endCol to which colum
	 */
	void swap(int startRow, int startCol, int endRow, int endCol);

	/**
	 *  Deletes the current container and replaces it with newContainer
	 *
	 *  @param {int**} newContainer
	 */
	void resetContainer(int** newContainer);
};

#endif /* SELECTION_H_ */
