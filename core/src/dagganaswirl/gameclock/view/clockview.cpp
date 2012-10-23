//
//  clockview.cpp
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/23/12.
//
//

#include "clockview.h"
#include "../../common/helper/platform.h"

GLfloat clockvertices[6];

void ClockView::initGL()
{
    clockvertices[0] = (float)m_geometry.width/2;
    clockvertices[1] = 0.0f;
    clockvertices[2] = 0.0f;
    clockvertices[3] = (float)m_geometry.height;
    clockvertices[4] = (float)m_geometry.width;
    clockvertices[5] = (float)m_geometry.height;
    
    m_initialized = true;
}

void ClockView::drawGL()
{
    if (m_initialized)
    {
        glPushMatrix();
        
        glTranslatef((GLfloat) m_geometry.x, (GLfloat)m_geometry.y, 0);
        
        glEnableClientState(GL_VERTEX_ARRAY);
        
        glVertexPointer(2, GL_FLOAT, 0, clockvertices);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glPopMatrix();
    }
    else
    {
        initGL();
    }
}