#pragma once

#include "../../gameboard/model/gameboard.h"

class Game
{
public:
	enum Difficulty
	{
		EASY = 4,
		MEDIUM = 5,
		HARD = 6
	};
	
	enum GameMode
	{
		TIMEATTACK = 20,
		LIMITEDMOVES = 21
	};
	
	Game(GameMode mode, Difficulty difficulty, GameBoard::Size boardSize);
	virtual ~Game() {}
	
	Difficulty getDifficulty();
	GameBoard & getBoard();
	
private:
	Difficulty m_difficulty;
	GameBoard m_gameBoard;
	GameMode m_gameMode;
};