//
//  buttonviewcpp.h
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/23/12.
//
//

#ifndef __DagganaSwirl__buttonviewcpp__
#define __DagganaSwirl__buttonviewcpp__

#import "../../common/view/openglview.h"

class ButtonView : public OpenGLView
{
public:
    void initGL();
    void drawGL();
};

#endif /* defined(__DagganaSwirl__buttonviewcpp__) */
