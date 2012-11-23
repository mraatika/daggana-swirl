//
//  boardview.cpp
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/21/12.
//
//

#include "boardview.h"
#include "../../common/helper/platform.h"
#include "dagganaapp.h"
#include "../../game/model/game.h"

GLfloat boardvertices[8];

void BoardView::initGL()
{
    boardvertices[0] = 0.0f;
    boardvertices[1] = 0.0f;
    boardvertices[2] = (float)m_geometry.width / (float)m_app->getGame()->getBoard().getSize();
    boardvertices[3] = 0.0f;
    boardvertices[4] = 0.0f;
    boardvertices[5] = (float)m_geometry.height / (float)m_app->getGame()->getBoard().getSize();
    boardvertices[6] = (float)m_geometry.width / (float)m_app->getGame()->getBoard().getSize();
    boardvertices[7] = (float)m_geometry.height / (float)m_app->getGame()->getBoard().getSize();
    
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
        for (int i=0; i < m_app->getGame()->getBoard().getSize(); i++)
        {
            for (int j=0; j < m_app->getGame()->getBoard().getSize(); j++)
            {
                int piece = m_app->getGame()->getBoard().getPiece(i, j);
                glPushMatrix();
                glColor4f(.1f * piece, .2f * piece, .3f * piece, 1.f);
                glTranslatef(
                             (float)(m_geometry.width / m_app->getGame()->getBoard().getSize() * i),
                             (float)(m_geometry.height / m_app->getGame()->getBoard().getSize() * j),
                             0)
                ;
                glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
                glPopMatrix();
            }
        }
        
        glPopMatrix();
    }
    else
    {
        initGL();
    }
}