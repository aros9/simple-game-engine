#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Player
{
private:
    sf::Vector2f m_Speed;


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

    Collider* m_Collider;

    bool m_CanJump;
    float m_JumpHeight;
    float m_JumpSpeed;
    
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

    void shoot(sf::Vector2i direction);

    void OnCollision(sf::Vector2f direction);
 
    void update(float elapsedTime);

};