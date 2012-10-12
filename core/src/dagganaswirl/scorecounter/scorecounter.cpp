#include "scorecounter.h"
#include "../game/model/game.h"

#include <vector>

#define MIN_GROUP_SIZE 4

ScoreCounter::ScoreCounter(Game * game)
{
	m_game = game;
	m_score = 0;
}

long ScoreCounter::getScore()
{
	return m_score;
}

int ** checked;
int boardSize;

void checkCoordinate(const int i, const int j, const GameBoard & board, int & groupSize)
{
	groupSize++;
	checked[i][j] = 1;
	const int pieceType = board.getPiece(i, j);
	
	if (i > 0 && checked[i-1][j] == 0 && board.getPiece(i-1, j) == pieceType)
	{
		checkCoordinate(i-1, j, board, groupSize);
	}

	if (i < boardSize-1 && checked[i+1][j] == 0 && board.getPiece(i+1, j) == pieceType)
	{
		checkCoordinate(i+1, j, board, groupSize);
	}
	 
	if (j > 0 && checked[i][j-1] == 0 && board.getPiece(i, j-1) == pieceType)
	{
		checkCoordinate(i, j-1, board, groupSize);
	}
	
	if (j < boardSize-1 && checked[i][j+1] == 0  && board.getPiece(i, j+1) == pieceType)
	{
		checkCoordinate(i, j+1, board, groupSize);
	}
}

void ScoreCounter::countScore()
{
	m_score = 0;
	boardSize = (int)m_game->getBoard().getSize();
	checked = new int*[boardSize];
	
	for (int i = 0; i < boardSize; i++)
	{
		checked[i] = new int[boardSize];
	}
	
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			checked[i][j] = 0;
		}
	}
	
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			if (checked[i][j] == 0)
			{		
				int groupSize = 0;
				checkCoordinate(i, j, m_game->getBoard(), groupSize);
				if (groupSize >= MIN_GROUP_SIZE)
				{
					m_score += groupSize * groupSize;
				}
			}
		}
	}
	
	for (int i = 0; i < boardSize; i++)
	{
		delete [] checked[i];
	}
	delete [] checked;
}

