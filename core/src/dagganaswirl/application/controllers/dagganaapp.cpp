#include "dagganaapp.h"

DagganaApp::DagganaApp()
{
    m_gameView = new GameView();
}

DagganaApp::~DagganaApp()
{
    delete m_gameView;
}

GameView * DagganaApp::getGameView()
{
    return m_gameView;
}