#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2i direction)
{
	m_Texture.loadFromFile("src/pocisk.png");
	m_Body.setTexture(&m_Texture);
	m_Body.setPosition(position);

	m_Body.setSize(sf::Vector2f(30.0f, 60.0f));
	m_Body.setOrigin(m_Body.getSize() / 2.0f);

	m_Collider = new Collider(m_Body);

	// calculate vector for move function
	m_Direction.x = (direction.x - position.x)/100;
	m_Direction.y = (direction.y - position.y)/100;

	m_Speed.x = 100.0f;
	m_Speed.y = 100.0f;
}

void Bullet::move(float elapsedTime)
{
	m_Position.x += m_Speed.x * elapsedTime;
	m_Position.y += m_Speed.y * elapsedTime;
	m_Body.setPosition(m_Position);
}