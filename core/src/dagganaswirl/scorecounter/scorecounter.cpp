#include "scorecounter.h"
#include "../game/model/game.h"

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


struct Coordinate
{
	Coordinate(int i, int j)
		: m_checked(false)
	{
		m_i = i;
		m_j = j;		
	}
	int m_i, m_j;
	bool m_checked;
};
/*
struct CoordinateList
{
	CoordinateList(int size)
		: m_coordinates[size]
	{
	}
	
	Coordinate[] m_coordinates;
};
*/
/*
int contains(Coordinate * coord, Coordinates[][] & coordinates, int pieceType)
{
	for (int i = 0; i < 
}
*/
void checkCoordinate(Coordinate * coord/*, Coordinate[][] & coordinates*/, int pieceType, int & groupSize)
{
    /*        
	coord->m_checked = true;
	
	int leftSideIndex = pieceTypeLists.get(pieceType).contains(coord.i, coord.j-1);
	if (leftSideIndex != -1 && !pieceTypeLists.get(pieceType).get(leftSideIndex).getChecked()) {
		groupSize++;
		checkCoordinate(pieceTypeLists.get(pieceType).get(leftSideIndex), pieceType);
	}
	int topSideIndex = pieceTypeLists.get(pieceType).contains(coord.i-1, coord.j);
	if (topSideIndex != -1 && !pieceTypeLists.get(pieceType).get(topSideIndex).getChecked()) {
		groupSize++;
		checkCoordinate(pieceTypeLists.get(pieceType).get(topSideIndex), pieceType);
	} 
	int rightSideIndex = pieceTypeLists.get(pieceType).contains(coord.i, coord.j+1);
	if (rightSideIndex != -1 && !pieceTypeLists.get(pieceType).get(rightSideIndex).getChecked()) {
		groupSize++;
		checkCoordinate(pieceTypeLists.get(pieceType).get(rightSideIndex), pieceType);
	}
	int bottomSideIndex = pieceTypeLists.get(pieceType).contains(coord.i+1, coord.j);
	if (bottomSideIndex != -1 && !pieceTypeLists.get(pieceType).get(bottomSideIndex).getChecked()) {
		groupSize++;
		checkCoordinate(pieceTypeLists.get(pieceType).get(bottomSideIndex), pieceType);
	}   
	*/
}

void ScoreCounter::countScore()
{
	m_score = 0;
	int difficulty = (int)m_game->getDifficulty();
	int pieceCount = (int)m_game->getBoard().getSize() * (int)m_game->getBoard().getSize() / difficulty;
	Coordinate * coordinates[difficulty][pieceCount];
	int counters[pieceCount];
	for (int i = 0; i < (int)m_game->getBoard().getSize() ; i++)
	{
		for (int j = 0; j < (int)m_game->getBoard().getSize() ; j++)
		{
			int pieceType = m_game->getBoard().getPiece(i, j);
			coordinates[pieceType][counters[pieceType]++]  = new Coordinate(i, j);
		}
	}
			
	for (int i = 0; i < difficulty; i++)
	{
		int groupSize = 0;
		for (int j = 0; j < pieceCount; j++)
		{
			if (!coordinates[i][j]->m_checked)
			{
				checkCoordinate(coordinates[i][j], i, groupSize);
				if (groupSize >= MIN_GROUP_SIZE)
				{
					m_score += groupSize * groupSize;
				}
			}
		}
	}
}

