#pragma once
#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class Player;

class Collider
{
private:
	sf::RectangleShape& m_Body;

public:
	Collider(sf::RectangleShape& body);
	//~Collider();

	void Move(float dx, float dy) { m_Body.move(dx, dy); }

	bool checkCollision(Collider* collider, sf::Vector2f& direction, float push);
	sf::Vector2f GetPosition() { return m_Body.getPosition(); }
	sf::Vector2f GetHalfSize() { return m_Body.getSize() / 2.0f; }

};

#endif