//
//  gameview.h
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/19/12.
//
//

#ifndef __DagganaSwirl__gameview__
#define __DagganaSwirl__gameview__

#include "../../common/view/openglview.h"
#include "../../gameboard/view/boardview.h"

#include <vector>

class GameView : public OpenGLView
{
public:
    GameView();
    
    void initGL();
    void drawGL();
    void resizeGL(int w, int h);
    
private:
    BoardView m_boardView;
    
    std::vector<OpenGLView *> m_views;
};

#endif /* defined(__DagganaSwirl__gameview__) */
