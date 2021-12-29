#include "Player.h"

Player::Player()
{
    m_Speed.x = 400.0f;
    m_Speed.y = 450.0f;

    m_JumpHeight = 100;

    m_Texture.loadFromFile("src/pengu.png");

    m_Body.setTexture(&m_Texture);

    m_Position.x = sf::VideoMode::getDesktopMode().width / 2.0f;
    m_Position.y = 900.0f;

    m_Body.setPosition(m_Position);
    
    m_Body.setSize(sf::Vector2f(100.0f, 150.0f));
    m_Body.setOrigin(m_Body.getSize() / 2.0f);

    m_Animation.setAnimation(&m_Texture, sf::Vector2u(3, 9), 0.3f);

    m_FaceRight = true;


    m_Collider = new Collider(m_Body);
    m_CanJump = true;
    m_JumpSpeed = 1500.0f;

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
    m_CanJump = false;
}

void Player::shoot(sf::Vector2i direction)
{
    m_Bullets.push_back(Bullet(m_Position, direction));
}

void Player::OnCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f)
    {
        //Right collision
        m_Speed.x = 0.0f;
    }
    else if (direction.x > 0.0f)
    {
        //Left collision
        m_Speed.x = 0.0f;
    }
    if (direction.y < 0.0f)
    {
        //Bottom collision
        m_Speed.y = 0;
        m_JumpSpeed = 1000.0f;
    }
    else if (direction.y > 0.0f)
    {
        //Top collision
        m_JumpSpeed = 0.0f;
    }
}


void Player::update(float elapsedTime)
{
    m_Row = 0;
    m_Speed.x = 400.0f;
    m_Speed.y = 450.0f;

    OnCollision(m_CollisionDirection);

        if (m_RightPressed)
        {
            if (m_CollisionDirection.x > 0.0f) m_Speed.x = 400.0f;
            m_Position.x += m_Speed.x * elapsedTime;
            m_FaceRight = true;
            m_Row = 1;
        }

        if (m_LeftPressed)
        {
            if (m_CollisionDirection.x < 0.0f) m_Speed.x = 400.0f;
            m_Position.x -= m_Speed.x * elapsedTime;
            m_FaceRight = false;
            m_Row = 1;
        }

    // gravity
     m_Position.y += m_Speed.y * elapsedTime;

     if (!m_CanJump)
     {
         if (m_JumpSpeed > 0.0f)
         {
             m_Row = 3;
             m_Position.y -= m_JumpSpeed * elapsedTime;
             m_JumpSpeed -= 1.0f;
         }
         else m_CanJump = true;
     }

    m_Body.setPosition(m_Position);

    m_Animation.UpdateAnimation(m_Row, elapsedTime, m_FaceRight);
    m_Body.setTextureRect(m_Animation.m_UvRect);

    m_CollisionDirection.x = 0.0f;
    m_CollisionDirection.y = 0.0f;

    for (Bullet& bullet : m_Bullets)
        bullet.move(elapsedTime);

}