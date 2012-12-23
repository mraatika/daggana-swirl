#pragma once

/**
 *  Class to represent a point in a matrix.
 *
 */
class Coordinate
{
public:
	Coordinate(int x, int y);
	virtual ~Coordinate();

	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	
private:
	int m_x;
	int m_y;
};