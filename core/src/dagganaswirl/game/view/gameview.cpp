//
//  gameview.cpp
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/19/12.
//
//
#include "../../common/helper/platform.h"
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

    GLfloat vertices[] = {  0.0f, 1.0f, 0.0f,
                            -1.0f,-1.0f, 0.0f,
                            1.0f,-1.0f, 0.0f};
    
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glDisableClientState(GL_VERTEX_ARRAY);
}