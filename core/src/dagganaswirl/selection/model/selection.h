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
	Selection(int** selection);
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
	 * Returns the size of a row (total size of the selection
	 * is getSize() * getSize())
	 *
	 * @returns {int} size of a row
	 */
	int getSize();
	int getPiece(int row, int col);

	/**
	 * Alters the selection as defined by the action parameter
	 *
	 * @param {ActionType} action The type of the action to perform
	 *
	 */
	void doAction(ActionType action);

private:
	int** m_container;

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
