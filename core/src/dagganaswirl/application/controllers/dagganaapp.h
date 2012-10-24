//
//  dagganaapp.h
//  DagganaSwirl
//
//  Created by Kimmo Keronen on 10/21/12.
//
//

#ifndef DagganaSwirl_dagganaapp_h
#define DagganaSwirl_dagganaapp_h

#include "../../game/model/game.h"

#include "../../game/view/gameview.h"

#include <vector>

class DagganaApp
{
public:
    DagganaApp(int width, int height);
    ~DagganaApp();
    
    bool playGame(Game::GameMode mode, Game::Difficulty difficulty);
    
    void resize(int width, int height);
    
    void draw();

private:
    std::vector<OpenGLView *> m_views;
    
    Game * m_game;
    
    int m_width, m_height;
};

#endif
