#pragma once

#include "../../game/model/game.h"

/**
*	Class that keeps track of remaining time.
*/
class GameClock
{
public: 
	GameClock(const Game::Difficulty difficulty);
        
    /**
    *	Starts the game clock.
    */
    void start();
    
    /**
    *	Returns the remaining time.
    *
    */
    const int getRemainingTime();
        
private:
	int totalTime;	
};