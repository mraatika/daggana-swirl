#pragma once

class Game;

class ScoreCounter
{
public:
	ScoreCounter(Game * game);
	virtual ~ScoreCounter() {}
	
	long getScore();
	
	void countScore();
	
private:
	long m_score;
	
	Game * m_game;
};


