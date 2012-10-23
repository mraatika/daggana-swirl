//
//  boardview.cpp
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/21/12.
//
//

#include "boardview.h"
#include "../../common/helper/platform.h"

GLfloat boardvertices[6];

void BoardView::initGL()
{
    boardvertices[0] = (float)m_geometry.width/2;
    boardvertices[1] = 0.0f;
    boardvertices[2] = 0.0f;
    boardvertices[3] = (float)m_geometry.height;
    boardvertices[4] = (float)m_geometry.width;
    boardvertices[5] = (float)m_geometry.height;
    
    m_initialized = true;
}

void BoardView::drawGL()
{
    if (m_initialized)
    {
        glPushMatrix();
        
        glTranslatef((GLfloat) m_geometry.x, (GLfloat)m_geometry.y, 0);
        glEnableClientState(GL_VERTEX_ARRAY);
        
        glVertexPointer(2, GL_FLOAT, 0, boardvertices);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glPopMatrix();
    }
    else
    {
        initGL();
    }
}