//
//  buttonviewcpp.cpp
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/23/12.
//
//

#include "buttonview.h"
#include "../../common/helper/platform.h"

GLfloat buttonvertices[6];

void ButtonView::initGL()
{
    buttonvertices[0] = (float)m_geometry.width/2;
    buttonvertices[1] = 0.0f;
    buttonvertices[2] = 0.0f;
    buttonvertices[3] = (float)m_geometry.height;
    buttonvertices[4] = (float)m_geometry.width;
    buttonvertices[5] = (float)m_geometry.height;
    
    m_initialized = true;
}

void ButtonView::drawGL()
{
    if (m_initialized)
    {
        glPushMatrix();
        
        glTranslatef((GLfloat) m_geometry.x, (GLfloat)m_geometry.y, 0);
        
        glEnableClientState(GL_VERTEX_ARRAY);
        
        glVertexPointer(2, GL_FLOAT, 0, buttonvertices);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glPopMatrix();
    }
    else
    {
        initGL();
    }
}