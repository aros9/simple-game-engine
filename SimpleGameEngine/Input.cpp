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
        m_Player->moveLeft();
    }
    else
    {
        m_Player->stopLeft();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_Player->moveRight();
    }
    else
    {
        m_Player->stopRight();
    }

    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    //{
    //    m_Player.moveUp();
    //}
    //else
    //{
    //    m_Player.stopUp();
    //}

    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    //{
    //    m_Player.moveDown();
    //}
    //else
    //{
    //    m_Player.stopDown();
    //}

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_Player->canJump())
    {
        m_Player->startJump();
    }
    else
    {
        m_Player->stopJump();
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // shoot
      //sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    }

}