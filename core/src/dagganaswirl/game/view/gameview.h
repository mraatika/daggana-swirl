//
//  gameview.h
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/19/12.
//
//

#ifndef __DagganaSwirl__gameview__
#define __DagganaSwirl__gameview__

class GameView
{
public:
    GameView();
    
    void initGL();
    void drawGL();
    void resizeGL(int w, int h);
    
private:
    int m_width, m_height;
};

#endif /* defined(__DagganaSwirl__gameview__) */
