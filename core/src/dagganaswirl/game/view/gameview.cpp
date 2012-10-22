//
//  gameview.cpp
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/19/12.
//
//
#include "../../common/helper/platform.h"
#include "gameview.h"

GameView::GameView()
{
    m_geometry.width = 600;
    m_geometry.height = 800;
}

GLfloat vertices[6];

void GameView::initGL()
{
    //2d setup
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho (0, m_geometry.width, m_geometry.height, 0, 1, -1);
    glViewport(0, 0, m_geometry.width, m_geometry.height);
    glMatrixMode (GL_MODELVIEW);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    
    vertices[0] = (float)m_geometry.width/2;
    vertices[1] = 0.0f;
    vertices[2] = 0.0f;
    vertices[3] = (float)m_geometry.height;
    vertices[4] = (float)m_geometry.width;
    vertices[5] = (float)m_geometry.height;
    
    m_views.push_back(&m_boardView);
    
    //initialize children views
    std::vector<OpenGLView *>::const_iterator it;
    for (it = m_views.begin(); it < m_views.end(); ++it)
    {
        (*it)->initGL();
    }
}

void GameView::drawGL()
{
    glClear(GL_COLOR_BUFFER_BIT);         // Clear The Screen And The Depth
    glLoadIdentity();
    
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    
    //Drawing of children views
    std::vector<OpenGLView *>::const_iterator it;
    for (it = m_views.begin(); it < m_views.end(); ++it)
    {
        (*it)->drawGL();
    }
}

void GameView::resizeGL(int w, int h)
{
    m_geometry.height = h;
    m_geometry.width = w;
}