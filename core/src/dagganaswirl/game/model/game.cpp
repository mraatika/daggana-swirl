#include "game.h"
#include "../../selection/model/selection.h"
#include <iostream>

Game::Game(const DagganaApp * app, GameMode mode, Difficulty difficulty, GameBoard::Size boardSize)
	: m_difficulty(difficulty), m_gameBoard(app, boardSize), m_gameMode(mode)
{

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
