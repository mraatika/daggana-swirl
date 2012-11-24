//
//  buttonviewcpp.h
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/23/12.
//
//

#ifndef __DagganaSwirl__buttonviewcpp__
#define __DagganaSwirl__buttonviewcpp__

#include "../../common/view/openglview.h"

class ButtonView : public OpenGLView
{
public:
    
    ~ButtonView() {}
    void initGL();
    void drawGL();
    virtual void mousePressed(const int , const int y) {}
    virtual void mouseReleased(const int , const int y) {}
};

#endif /* defined(__DagganaSwirl__buttonviewcpp__) */
