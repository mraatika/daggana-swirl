//
//  scoreview.h
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/23/12.
//
//

#ifndef __DagganaSwirl__scoreview__
#define __DagganaSwirl__scoreview__

#import "../../common/view/openglview.h"

class ScoreView : public OpenGLView
{
public:
    void initGL();
    void drawGL();
};

#endif /* defined(__DagganaSwirl__scoreview__) */
