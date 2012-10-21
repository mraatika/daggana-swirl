//
//  dagganaapp.h
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/21/12.
//
//

#ifndef DagganaSwirl_dagganaapp_h
#define DagganaSwirl_dagganaapp_h

#include "../../game/view/gameview.h"

class DagganaApp
{
public:
    DagganaApp();
    ~DagganaApp();
    
    GameView * getGameView();

private:
    GameView * m_gameView;
};

#endif
