#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();
	~Animation();

	void setAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

	void UpdateAnimation(int row, float deltaTime, bool faceRight);

	sf::IntRect m_UvRect;

private:
	sf::Vector2u m_ImageCount;
	sf::Vector2u m_CurrentImage;

	float m_TotalTime;
	float m_SwitchTime;
};

