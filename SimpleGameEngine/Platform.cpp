#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	m_Body.setSize(size);
	m_Body.setOrigin(size / 2.0f);
	m_Body.setTexture(texture);
	m_Body.setPosition(position);
}