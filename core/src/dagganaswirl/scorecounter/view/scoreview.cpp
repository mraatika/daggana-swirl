//
//  scoreview.cpp
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/23/12.
//
//

#include "scoreview.h"
#include "../../common/helper/platform.h"

GLfloat scorekvertices[6];

void ScoreView::initGL()
{
    scorekvertices[0] = (float)m_geometry.width/2;
    scorekvertices[1] = 0.0f;
    scorekvertices[2] = 0.0f;
    scorekvertices[3] = (float)m_geometry.height;
    scorekvertices[4] = (float)m_geometry.width;
    scorekvertices[5] = (float)m_geometry.height;
    
    m_initialized = true;
}

void ScoreView::drawGL()
{
    if (m_initialized)
    {
        glPushMatrix();
        
        glTranslatef((GLfloat) m_geometry.x, (GLfloat)m_geometry.y, 0);
        
        glEnableClientState(GL_VERTEX_ARRAY);
        
        glVertexPointer(2, GL_FLOAT, 0, scorekvertices);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glPopMatrix();
    }
    else
    {
        initGL();
    }
}