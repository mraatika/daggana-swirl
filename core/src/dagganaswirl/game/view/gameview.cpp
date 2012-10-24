//
//  gameview.cpp
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/19/12.
//
//
#include "assert.h"

#include "../../common/helper/platform.h"
#include "gameview.h"

GameView::GameView(int width, int height)
{
    sizeGL(0, 0, width, height);
    
    m_views.push_back(&m_buttonView);
    m_views.push_back(&m_scoreView);
    m_views.push_back(&m_boardView);
    m_views.push_back(&m_clockView);
}

void GameView::initGL()
{
    assert(m_geometry.width > 0 && m_geometry.height > 0);
    
    
    //2d setup
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho (m_geometry.x, m_geometry.width, m_geometry.height, m_geometry.y, 1, -1);
    glViewport(m_geometry.x, m_geometry.y, m_geometry.width, m_geometry.height);
    glMatrixMode (GL_MODELVIEW);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    
    m_initialized = true;
}

void GameView::drawGL()
{
    if (m_initialized)
    {
        glClear(GL_COLOR_BUFFER_BIT);         // Clear The Screen And The Depth
        glLoadIdentity();
        
        //Drawing of children views
        std::vector<OpenGLView *>::const_iterator it;
        for (it = m_views.begin(); it != m_views.end(); ++it)
        {
           (*it)->drawGL();
        }
    }
    else
    {
        initGL();
    }
}

void GameView::sizeGL(int x, int y, int width, int height)
{
    OpenGLView::sizeGL(x, y, width, height);
    updateLayout();
}

void GameView::updateLayout()
{
    if (m_geometry.width > 0 && m_geometry.height > 0)
    {
        if (m_geometry.width > m_geometry.height)
        {
            //Landscape
            
            m_scoreView.sizeGL(0,
                               (int)(0.3 * m_geometry.height),
                               (int)(0.2 * m_geometry.width),
                               (int)(0.7 * m_geometry.height));
            
            m_clockView.sizeGL(0,
                               0,
                               (int)(0.2 * m_geometry.width),
                               (int)(0.3 * m_geometry.height));
            
            m_buttonView.sizeGL((int)(0.2 * m_geometry.width),
                                (int)(0.8 * m_geometry.height),
                                (int)(0.8 * m_geometry.width),
                                (int)(0.2 * m_geometry.height));
            
            m_boardView.sizeGL((int)(0.2 * m_geometry.width),
                               0,
                               (int)(0.8 * m_geometry.width),
                               (int)(0.8 * m_geometry.height));
            
        }
        else
        {
            //Portrait
            
            m_scoreView.sizeGL(0, 0, (int)(0.7 * m_geometry.width),
                               (int)(0.2 * m_geometry.height));
            m_clockView.sizeGL((int)(0.7 * m_geometry.width), 0, (int)(0.3 * m_geometry.width),
                               (int)(0.2 * m_geometry.height));
            m_buttonView.sizeGL(0, (int)(0.2 * m_geometry.height),
                                (int)(0.2 * m_geometry.width),
                                (int)(0.8 * m_geometry.height));
            m_boardView.sizeGL((int)(0.2 * m_geometry.width),
                               (int)(0.2 * m_geometry.height),
                               (int)(0.8 * m_geometry.width),
                               (int)(0.8 * m_geometry.height));
        }
    }
}