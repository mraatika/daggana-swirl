#include "coordinate.h"

Coordinate::Coordinate(int x, int y) 
{
	m_x = x;
	m_y = y;
}

Coordinate::~Coordinate() 
{

}

int Coordinate::getX() 
{
	return m_x;
}

int Coordinate::getY() 
{
	return m_y;
}

void Coordinate::setX(int x)
{
	m_x = x;
}

void Coordinate::setY(int y)
{
	m_y = y;
}
