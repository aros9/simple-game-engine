#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Collider;

class Player
{
private:
    float m_Speed;

    sf::Vector2f m_Position;

    sf::Texture m_Texture;

    sf::RectangleShape m_Body;
    Animation m_Animation;

    sf::Vector2f m_CollisionDirection; 


    // row of a sprite needed to do animation
    unsigned int m_Row;

    bool m_FaceRight;

    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_SpacePressed;
    //bool m_DownPressed;

    bool m_rightCollision;
    bool m_leftCollision;
    bool m_downCollision;

    Collider* m_Collider;

    bool m_CanJump;
    float m_JumpHeight;
    
public:
    Player();

    sf::RectangleShape getBody() { return m_Body; };
    sf::Vector2f getPosition() { return m_Position; };
    Collider* getCollider() { return m_Collider; };
    sf::Vector2f& getDirection() { return m_CollisionDirection; };
    bool canJump() { return m_CanJump; };

    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    void startJump();
    void stopJump();

    void setRightCollision(bool _col);
    void setLeftCollision(bool _col);
    void setDownCollision(bool _col);

    //void moveUp();
    //void stopUp();
    //void moveDown();
    //void stopDown();

    void OnCollision(sf::Vector2f direction);
 
    void update(float elapsedTime);

};

#endif