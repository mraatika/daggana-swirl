#pragma once

/**
 *  Struct to define view geometry.
 */ 
struct Geometry
{
	int x, y, width, height;
    Geometry()
    {
        x = y = width = height = 0;
    }
    
    bool contains(const int _x, const int _y) const
    {
        if (_x >= x && _x <= width && _y >= y && _y <= height)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
/**
 *	Interface class to define functions, DagganaSwirl view classes
 *	should implement.
 */
class DagganaApp;

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
    
    virtual void mousePressed(const int x, const int y) = 0;
    
    virtual void mouseReleased(const int x, const int y) = 0;
    
    virtual void mouseMoved(const int x, const int y) = 0;
    
    void setApp(const DagganaApp * app) { m_app = app; }
    
    bool contains(const int _x, const int _y) const
    {
        return m_geometry.contains(_x, _y);
    }
    
    bool mouseIsDown() { return m_mouseIsDown; }
	
protected:
	Geometry m_geometry;
    bool m_initialized;
    const DagganaApp * m_app;
    bool m_mouseIsDown;
};