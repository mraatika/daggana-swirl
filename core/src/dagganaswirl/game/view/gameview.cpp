//
//  gameview.cpp
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/19/12.
//
//
#include "../../common/helper/paltform.h"
#include "gameview.h"

void GameView::initGL()
{
    glShadeModel(GL_SMOOTH);
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    
    glClearDepth(1.0f);                         // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);                        // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);                         // The Type Of Depth Test To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);          // Really Nice Perspective Calculations


}

void GameView::drawGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);         // Clear The Screen And The Depth
    glLoadIdentity();
    
    glBegin(GL_TRIANGLES);                      // Drawing Using Triangles
        glVertex3f( 0.0f, 1.0f, 0.0f);              // Top
        glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
        glVertex3f( 1.0f,-1.0f, 0.0f);              // Bottom Right
    glEnd();                            // Finished Drawing The Triangle

}