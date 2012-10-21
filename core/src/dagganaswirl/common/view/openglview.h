#pragma once

/**
 *  Struct to defien view geometry.
 */ 
struct Geometry
{
	int x, y, width, height;
}; 
/**
 *	Interface class to define functions, DagganaSwirl view classes
 *	should implement.
 */
class OpenGLView
{
public:
	virtual void initGL() = 0;
	virtual void drawGL() = 0;
	virtual void resizeGL(int width, int height) = 0;
	
protected:
	Geometry m_geometry;
};