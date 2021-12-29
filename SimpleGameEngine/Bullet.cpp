#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2i direction)
{
	m_Texture.loadFromFile("src/pocisk.png");
	m_Body.setTexture(&m_Texture);
	m_Body.setPosition(position);

	m_Body.setSize(sf::Vector2f(30.0f, 60.0f));
	//m_Body.setOrigin(m_Body.getSize() / 2.0f);

	m_Collider = new Collider(m_Body);

	// calculate vector for move function
	m_Direction.x = abs((direction.x - position.x));
	m_Direction.y = abs((direction.y - position.y));
}

void Bullet::move(float elapsedTime)
{
	m_Position.x += m_Direction.x * elapsedTime;
	m_Position.y += m_Direction.y * elapsedTime;
	m_Body.setPosition(m_Position);
}