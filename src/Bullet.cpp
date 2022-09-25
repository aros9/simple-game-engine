#include "../inc/Bullet.hpp"

Bullet::Bullet(sf::Vector2f position, sf::Vector2i direction)
{
	m_Texture.loadFromFile("src/pocisk.jpg");
	m_Body.setTexture(&m_Texture);
	m_Position = position;
	m_Body.setPosition(m_Position);
	printf("Bullet position X: %f, Y: %f\n", m_Position.x, m_Position.y);

	m_Body.setSize(sf::Vector2f(30.0f, 60.0f));
	m_Body.setOrigin(m_Body.getSize() / 2.0f);

	m_Collider = new Collider(m_Body);
	printf("Collider position X: %f, Y: %f\n", getCollider()->GetPosition().x, getCollider()->GetPosition().y);
	m_Speed = 1000.0f;

	// calculate vector for move function
	m_Direction.x = (direction.x - position.x);
	m_Direction.y = (direction.y - position.y);
	
	if (abs(m_Direction.x) >= abs(m_Direction.y))
	{
		m_Ratio = abs(m_Direction.y / m_Direction.x);
		if (m_Direction.y >= 0) m_Direction.y = m_Ratio * m_Speed;
		else m_Direction.y = -m_Ratio * m_Speed;
		if (m_Direction.x >= 0) m_Direction.x = (1 - m_Ratio) * m_Speed;
		else m_Direction.x = -(1 - m_Ratio) * m_Speed;
	}
	else
	{
		m_Ratio = abs(m_Direction.x / m_Direction.y);
		if (m_Direction.y >= 0) m_Direction.y = (1 - m_Ratio) * m_Speed;
		else m_Direction.y = -(1 - m_Ratio) * m_Speed;
		if (m_Direction.x >= 0) m_Direction.x = m_Ratio * m_Speed;
		else m_Direction.x = -m_Ratio * m_Speed;
	}

	m_CollisionDirection.x = 0;
	m_CollisionDirection.y = 0;

}

void Bullet::move(float elapsedTime)
{
	m_Position.x += m_Direction.x * elapsedTime;
	m_Position.y += m_Direction.y * elapsedTime;
	//printf("Bullet position X: %f, Y: %f\n", m_Position.x, m_Position.y);
	//printf("Collider position X: %f, Y: %f\n", getCollider()->GetPosition().x, getCollider()->GetPosition().y);
	m_Body.setPosition(m_Position);

	//m_CollisionDirection.x = 0.0f;
	//m_CollisionDirection.y = 0.0f;
}