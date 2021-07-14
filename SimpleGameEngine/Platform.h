#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

class Platform
{
private:
	sf::RectangleShape m_Body;
	
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	//~Platform();

	Collider getCollider() { return Collider(m_Body); };

	sf::RectangleShape getBody() { return m_Body; };
};

