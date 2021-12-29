#include "Engine.h"

void Engine::input()
{
    // Handle the player quitting
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        m_Window.close();
    }

    // Handle the player moving
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_Player.moveLeft();
    }
    else
    {
        m_Player.stopLeft();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_Player.moveRight();
    }
    else
    {
        m_Player.stopRight();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_Player.canJump())
    {
        m_Player.startJump();
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // shoot
        sf::Vector2i mousePos = sf::Mouse::getPosition(m_Window);
        m_Player.shoot(mousePos);
    }

}