#include "Player.h"

Player::Player()
{
    m_Speed = 400;
    m_JumpHeight = 100;

    m_Texture.loadFromFile("src/pengu.png");

    m_Body.setTexture(&m_Texture);

    m_Position.x = sf::VideoMode::getDesktopMode().width / 2.0f;
    m_Position.y = sf::VideoMode::getDesktopMode().height / 2.0f;

    // necessary ?
    m_Body.setPosition(m_Position);
    
    m_Body.setSize(sf::Vector2f(100.0f, 150.0f));
    m_Body.setOrigin(m_Body.getSize() / 2.0f);

    m_Animation.setAnimation(&m_Texture, sf::Vector2u(3, 9), 0.3f);

    m_FaceRight = true;


    m_Collider = new Collider(m_Body);
    m_CanJump = true;

    m_CollisionDirection.x = 0;
    m_CollisionDirection.y = 0;
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

void Player::startJump()
{
    m_SpacePressed = true;
}

void Player::stopJump()
{
    m_SpacePressed = false;
}

void Player::OnCollision(sf::Vector2f direction)
{
    if (direction.y == -1.0f) m_CanJump = true;
}


void Player::update(float elapsedTime)
{
    m_Row = 0;
    if (m_CollisionDirection.x != 1)
    {
        if (m_RightPressed)
        {
            m_Position.x += m_Speed * elapsedTime;
            m_FaceRight = true;
            m_Row = 1;
        }
    }
    if (m_CollisionDirection.x != -1)
    {
        if (m_LeftPressed)
        {
            m_Position.x -= m_Speed * elapsedTime;
            m_FaceRight = false;
            m_Row = 1;
        }
    }


    // gravity
    if(m_CollisionDirection.y != -1 ) m_Position.y += 98.1f * elapsedTime;

    OnCollision(m_CollisionDirection);

    // need to change jumping
    /*if (m_SpacePressed && m_CollisionDirection.y != -1)
    {
        m_CanJump = false;
        m_Position.y -= sqrtf(2.0f * 98.1f * m_JumpHeight);
    }*/

    m_Body.setPosition(m_Position);

    m_Animation.UpdateAnimation(m_Row, elapsedTime, m_FaceRight);
    m_Body.setTextureRect(m_Animation.m_UvRect);

}