//
//  boardview.h
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/21/12.
//
//

#ifndef __DagganaSwirl__boardview__
#define __DagganaSwirl__boardview__

#import "../../common/view/openglview.h"

class BoardView : public OpenGLView
{
public:
    
    ~BoardView() {}
    void initGL();
    void drawGL();
};

#endif /* defined(__DagganaSwirl__boardview__) */
