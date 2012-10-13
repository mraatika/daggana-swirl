#include "gameclock.h"

#include <time.h>

#define BASE_TIME 1000;

GameClock::GameClock(const Game::Difficulty difficulty)
{
	/**
	*	Total time at the beginning depends on game difficulty.
	*/
	totalTime = BASE_TIME - (int)difficulty * 100;
}

time_t startTime;

void GameClock::start()
{
	startTime = time(0);	
}

const int GameClock::getRemainingTime()
{
	int remaining = totalTime - (int)time(0) - (int)startTime;
	if (remaining <= 0)
	{
		remaining = 0;
	}
	return remaining; 
}