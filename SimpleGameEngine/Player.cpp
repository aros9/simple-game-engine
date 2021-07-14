#include "Player.h"

Player::Player()
{
    m_Speed = 400;
    m_JumpHeight = 100;

    m_Texture.loadFromFile("src/pengu.png");

    m_Body.setTexture(&m_Texture);

  //  m_Position.x = 960;
  //  m_Position.y = 880;

    m_Position.x = sf::VideoMode::getDesktopMode().width / 2.0f;
    m_Position.y = sf::VideoMode::getDesktopMode().height / 2.0f;

    // necessary ?
    m_Body.setPosition(m_Position);
    
    m_Body.setSize(sf::Vector2f(100.0f, 150.0f));
    m_Body.setOrigin(m_Body.getSize() / 2.0f);

    m_Animation.setAnimation(&m_Texture, sf::Vector2u(3, 9), 0.3f);

    m_FaceRight = true;

    m_rightCollision = false;
    m_leftCollision = false;
    m_downCollision = true;

    m_Collider = new Collider(m_Body);
}

void Player::moveLeft()
{
    m_LeftPressed = true;
}

void Player::moveRight()
{
    m_RightPressed = true;
}

void Player::stopLeft()
{
    m_LeftPressed = false;
}

void Player::stopRight()
{
    m_RightPressed = false;
}

void Player::setRightCollision(bool _col)
{
    m_rightCollision = _col;
}

void Player::setLeftCollision(bool _col)
{
    m_leftCollision = _col;
}

void Player::setDownCollision(bool _col)
{
    m_downCollision = _col;
}

void Player::moveUp()
{
    m_UpPressed = true;
}

void Player::stopUp()
{
    m_UpPressed = false;
}


void Player::moveDown()
{
    m_DownPressed = true;
}

void Player::stopDown()
{
    m_DownPressed = false;
}

void Player::jump()
{
    m_CanJump = false;
    m_Position.y = -sqrtf(2.0f * 981.0f * m_JumpHeight); // 100 units - 1 meter
}

void Player::OnCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f)
    {
        // Left collision
        m_Position.x = 0.0f;
    }
    else if (direction.x > 0.0f)
    {
        // Right collision
        m_Position.x = 0.0f;
    }
    if (direction.y < 0.0f)
    {
        // Bottom collision
        m_Position.y = 0.0f;
        m_CanJump = true;
    }
    else if (m_Position.y > 0.0f)
    {
        // Top collision
        m_Position.y = 0.0f;
    }
}

void Player::update(float elapsedTime)
{
    m_Row = 0;
   // if (!m_rightCollision)
    //{
        if (m_RightPressed)
        {
            m_Position.x += m_Speed * elapsedTime;
            m_FaceRight = true;
            m_Row = 1;
        }
   // }
  //  if (!m_leftCollision)
   // {
        if (m_LeftPressed)
        {
            m_Position.x -= m_Speed * elapsedTime;
            m_FaceRight = false;
            m_Row = 1;
        }
  //  }


    // gravity
   // m_Position.y += 98.1f * elapsedTime;

    if (m_UpPressed)
    {
        m_Position.y -= m_Speed * elapsedTime;
    }

    if (m_DownPressed)
    {
        m_Position.y += m_Speed * elapsedTime;
    }

    m_Body.setPosition(m_Position);

    m_Animation.UpdateAnimation(m_Row, elapsedTime, m_FaceRight);
    m_Body.setTextureRect(m_Animation.m_UvRect);

}