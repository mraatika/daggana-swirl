#include "game.h"
#include "../../common/model/coordinate.h"
#include "../../selection/model/selection.h"
#include <iostream>

Game::Game(const DagganaApp * app, GameMode mode, Difficulty difficulty, GameBoard::Size boardSize)
	: m_difficulty(difficulty), m_gameBoard(app, boardSize), m_gameMode(mode)
{
	// @STARTOF: Debugging stuff
	Selection* selection = new Selection(5);
	int counter = 1;

	for (int i = 0; i < 25; i++) 
	{
		selection->add(counter++);
	}

	selection->doAction(Selection::MIRROR_HORIZONTALLY);

	//selection->printOut();

	std::cout << std::endl;
	std::cout << std::endl;
	
	counter = 1;

	for (int i = 0; i < boardSize; i++) 
	{
		for (int j = 0; j < boardSize; j++) 
		{
			m_gameBoard.setPiece(i, j, counter++);		
		}
	}

	Coordinate start = Coordinate(1, 0);

	Selection * newSelection = m_gameBoard.createSelection(start, Coordinate(2, 1));

	newSelection->doAction(Selection::MIRROR_HORIZONTALLY);

	newSelection->printOut();

	m_gameBoard.mergeSelection(newSelection, start);

	m_gameBoard.printOut();

	delete selection;
	delete newSelection;
	//@ENDOF: Debugging stuff
}

Game::Difficulty Game::getDifficulty() const
{
    return m_difficulty;
}

const GameBoard & Game::getBoard() const
{
	return m_gameBoard;
}

void Game::initialize()
{
    m_gameBoard.initialize();
}
