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
};

#endif /* defined(__DagganaSwirl__buttonviewcpp__) */
