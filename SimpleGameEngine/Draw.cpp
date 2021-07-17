#include "Engine.h"

void Engine::draw()
{
    // Rub out the last frame
    m_Window.clear(sf::Color::White);

    // Draw the background
    m_Window.draw(m_BackgroundSprite);
    m_Window.draw(m_Player.getBody());

    // Draw platforms
    for (Platform& platform : platforms)
        m_Window.draw(platform.getBody());

    // Show everything we have just drawn
    m_Window.display();
}