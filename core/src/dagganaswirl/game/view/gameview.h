//
//  gameview.h
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/19/12.
//
//

#ifndef __DagganaSwirl__gameview__
#define __DagganaSwirl__gameview__

#include "../../common/view/openglview.h"
#include "../../gameboard/view/boardview.h"
#include "../../gameclock/view/clockview.h"
#include "../../scorecounter/view/scoreview.h"
#include "../../button/view/buttonview.h"

#include <vector>

class DagganaApp;

class GameView : public OpenGLView
{
public:
    GameView(const DagganaApp * app, const int width, const int height);
    ~GameView() {}
    
    //Overriden OpenGLView functions
    void initGL();
    void drawGL();
    void sizeGL(int x, int y, int width, int height);
    
private:
    void updateLayout();
    
//member variables
private:
    BoardView m_boardView;
    ClockView m_clockView;
    ScoreView m_scoreView;
    ButtonView m_buttonView;
    
    std::vector<OpenGLView *> m_views;
};

#endif /* defined(__DagganaSwirl__gameview__) */
