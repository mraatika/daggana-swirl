//
//  clockview.h
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/23/12.
//
//

#ifndef __DagganaSwirl__clockview__
#define __DagganaSwirl__clockview__

#import "../../common/view/openglview.h"

class ClockView : public OpenGLView
{
public:
    void initGL();
    void drawGL();
};

#endif /* defined(__DagganaSwirl__clockview__) */
