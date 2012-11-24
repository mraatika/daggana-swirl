//
//  scoreview.h
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/23/12.
//
//

#ifndef __DagganaSwirl__scoreview__
#define __DagganaSwirl__scoreview__

#include "../../common/view/openglview.h"

class ScoreView : public OpenGLView
{
public:
    
    ~ScoreView() {}
    void initGL();
    void drawGL();
    virtual void mousePressed(const int , const int y) {}
    virtual void mouseReleased(const int , const int y) {}
};

#endif /* defined(__DagganaSwirl__scoreview__) */
