#include "dagganaapp.h"

#include "assert.h"

DagganaApp::DagganaApp(const int width, const int height)
: m_width(width), m_height(height)
{
    //test game and view
    m_game = new Game(this, Game::TIMEATTACK, Game::HARD, GameBoard::MEDIUM);
    m_game->initialize();
    m_views.push_back(new GameView(this, width, height));
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

void DagganaApp::resize(const int width, const int height)
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

void DagganaApp::draw() const
{
    //check if there's any views to draw
    assert(!m_views.empty());
    
    m_views.back()->drawGL();
}

const Game * DagganaApp::getGame() const
{
    return m_game;
}