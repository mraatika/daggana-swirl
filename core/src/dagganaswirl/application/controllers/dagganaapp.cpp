#include "dagganaapp.h"

#include "assert.h"

DagganaApp::DagganaApp(int width, int height)
: m_width(width), m_height(height)
{
    //test game and view
    m_game = new Game(Game::TIMEATTACK, Game::MEDIUM, GameBoard::MEDIUM);
    m_views.push_back(new GameView(width, height));
}

DagganaApp::~DagganaApp()
{
    std::vector<OpenGLView *>::const_iterator it;
    for (it = m_views.begin(); it != m_views.end(); ++it)
    {
        delete *it;
    }
    
    delete m_game;
}

bool DagganaApp::playGame(Game::GameMode mode, Game::Difficulty difficulty)
{
    return true;
}

void DagganaApp::resize(int width, int height)
{
    m_width = width;
    m_height = height;
    
    //check if there's any views to draw
    assert(!m_views.empty());
    
    std::vector<OpenGLView *>::const_iterator it;
    for (it = m_views.begin(); it != m_views.end(); ++it)
    {
        (*it)->sizeGL(0, 0, m_width, m_height);
    }
}

void DagganaApp::draw()
{
    //check if there's any views to draw
    assert(!m_views.empty());
    
    m_views.back()->drawGL();
}