//
//  boardview.h
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/21/12.
//
//

#ifndef __DagganaSwirl__boardview__
#define __DagganaSwirl__boardview__

#include "../../common/view/openglview.h"

class BoardView : public OpenGLView
{
public:
    
    ~BoardView() {}
    void initGL();
    void drawGL();
    virtual void mousePressed(const int , const int y) {}
    virtual void mouseReleased(const int , const int y) {}
};

#endif /* defined(__DagganaSwirl__boardview__) */
