#include "game.h"
#include "../../selection/model/selection.h"
#include <iostream>

Game::Game(GameMode mode, Difficulty difficulty, GameBoard::Size boardSize)
	: m_gameBoard(boardSize), m_difficulty(difficulty), m_gameMode(mode)
{

}

Game::Difficulty Game::getDifficulty()
{
	return m_difficulty;
}

GameBoard & Game::getBoard()
{
	return m_gameBoard;
}