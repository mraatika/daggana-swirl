#pragma once

/**
 *  Struct to defien view geometry.
 */ 
struct Geometry
{
	int x, y, width, height;
    Geometry()
    {
        x = y = width = height = 0;
    }
}; 
/**
 *	Interface class to define functions, DagganaSwirl view classes
 *	should implement.
 */
class OpenGLView
{
public:
    
    OpenGLView() { m_initialized = false; }
    virtual ~OpenGLView() {}
    
	virtual void initGL() = 0;
	virtual void drawGL() = 0;
	virtual void sizeGL(int x, int y, int width, int height)
    {
        m_geometry.x = x;
        m_geometry.y = y;
        m_geometry.width = width;
        m_geometry.height = height;
        
        m_initialized = false;
    }
	
protected:
	Geometry m_geometry;
    bool m_initialized;
};