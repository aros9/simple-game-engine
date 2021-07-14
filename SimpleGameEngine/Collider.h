#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
private:
	sf::RectangleShape& m_Body;

public:
	Collider(sf::RectangleShape& body);
	//~Collider();

	void Move(float dx, float dy) { m_Body.move(dx, dy); }

	bool checkCollision(Collider* other,sf::Vector2f& direction, float push);
	sf::Vector2f GetPosition() { return m_Body.getPosition(); }
	sf::Vector2f GetHalfSize() { return m_Body.getSize() / 2.0f; }

};

