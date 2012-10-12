#include "game.h"

Game::Game()
	: gameBoard(GameBoard::MEDIUM)
{
	difficulty = Game::EASY;
}

Game::Difficulty Game::getDifficulty()
{
	return difficulty;
}

GameBoard & Game::getBoard()
{
	return gameBoard;
}