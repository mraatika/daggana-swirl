#include "game.h"
#include "../../selection/model/selection.h"
#include <iostream>

Game::Game(const DagganaApp * app, GameMode mode, Difficulty difficulty, GameBoard::Size boardSize)
	: m_difficulty(difficulty), m_gameBoard(app, boardSize), m_gameMode(mode)
{
	Selection* selection = new Selection(5);
	int counter = 1;

	for (int i = 0; i < 25; i++) 
	{
		selection->add(counter++);
	}

	selection->doAction(Selection::MIRROR_HORIZONTALLY);

	selection->printOut();

	std::cout << std::endl;

	delete selection;
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
