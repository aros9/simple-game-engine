#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

class Bullet
{
private:
	sf::Texture m_Texture;
	sf::RectangleShape m_Body;
	sf::Vector2f m_Position;
	sf::Vector2f m_Direction;
	Collider* m_Collider;
public:
	Bullet(sf::Vector2f position, sf::Vector2i direction);
	sf::RectangleShape getBody() { return m_Body; }
	void move(float elapsedTime);
};

