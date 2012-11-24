//
//  clockview.h
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/23/12.
//
//

#ifndef __DagganaSwirl__clockview__
#define __DagganaSwirl__clockview__

#include "../../common/view/openglview.h"

class ClockView : public OpenGLView
{
public:
    
    ~ClockView() {}
    void initGL();
    void drawGL();
    virtual void mousePressed(const int x, const int y) {}
    virtual void mouseReleased(const int x, const int y) {}
    virtual void mouseMoved(const int x, const int y) {}
};

#endif /* defined(__DagganaSwirl__clockview__) */
