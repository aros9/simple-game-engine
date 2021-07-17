#include "Player.h"

Player::Player()
{
    m_Speed.x = 400;
    m_Speed.y = 0;

    m_JumpHeight = 100;

    m_Texture.loadFromFile("src/pengu.png");

    m_Body.setTexture(&m_Texture);

    m_Position.x = sf::VideoMode::getDesktopMode().width / 2.0f;
    m_Position.y = 900;

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
    if (direction.x < 0.0f)
    {
        //Left collision
        m_Speed.x = 0.0f;
    }
    else if (direction.x > 0.0f)
    {
        //Right collision
        m_Speed.x = 0.0f;
    }
    if (direction.y < 0.0f)
    {
        //Bottom collision
        m_CanJump = true;
        m_Speed.y = 0.0f;
    }
    else if (direction.y > 0.0f)
    {
        //Top collision
        m_Speed.y = 0.0f;
    }
}


void Player::update(float elapsedTime)
{
    m_Row = 0;
    m_Speed.x = 400;
    m_Speed.y = 98.1f;


    OnCollision(m_CollisionDirection);

        if (m_RightPressed)
        {
            if (m_CollisionDirection.x > 0.0f) m_Speed.x = 400;
            m_Position.x += m_Speed.x * elapsedTime;
            m_FaceRight = true;
            m_Row = 1;
        }

        if (m_LeftPressed)
        {
            if (m_CollisionDirection.x < 0.0f) m_Speed.x = 400;
            m_Position.x -= m_Speed.x * elapsedTime;
            m_FaceRight = false;
            m_Row = 1;
        }

    // gravity
     m_Position.y += m_Speed.y * elapsedTime;

    // need to change jumping
    /*if (m_SpacePressed && m_CollisionDirection.y != -1)
    {
        m_CanJump = false;
        m_Position.y -= sqrtf(2.0f * 98.1f * m_JumpHeight);
    }*/

    m_Body.setPosition(m_Position);

    m_Animation.UpdateAnimation(m_Row, elapsedTime, m_FaceRight);
    m_Body.setTextureRect(m_Animation.m_UvRect);

    m_CollisionDirection.x = 0.0f;
    m_CollisionDirection.y = 0.0f;

}