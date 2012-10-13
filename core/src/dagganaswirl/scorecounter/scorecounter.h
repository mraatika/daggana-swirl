#pragma once

class Game;

/**
*	Class to count game score. 
*/
class ScoreCounter
{
public:
	ScoreCounter(Game * game);
	virtual ~ScoreCounter() {}
	
	/**
	*	Get current game score.
	*/
	long getScore();
	
private:
	/**
	*	Tell ScoreCounter to count.
	*/
	void countScore();
	
private:
	long m_score;
	
	Game * m_game;
};


