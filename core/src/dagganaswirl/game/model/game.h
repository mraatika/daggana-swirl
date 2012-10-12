#pragma once

#include "../../gameboard/model/gameboard.h"

class Game
{
public:

	Game();
	virtual ~Game() {}
	
	enum Difficulty
	{
		EASY = 4,
		MEDIUM = 5,
		HARD = 6
	};
	
	Difficulty getDifficulty();
	GameBoard & getBoard();
	
private:
	Difficulty difficulty;
	GameBoard gameBoard;
};