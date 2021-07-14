#include "Animation.h"

Animation::Animation()
{
	m_TotalTime = 0.0f;
	m_CurrentImage.x = 0;

	m_SwitchTime = 0;
}

Animation::~Animation()
{

}

void Animation::setAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	m_ImageCount = imageCount;
	m_SwitchTime = switchTime;



	m_UvRect.width = texture->getSize().x / float(imageCount.x);
	m_UvRect.height = texture->getSize().y / float(imageCount.y);
}

void Animation::UpdateAnimation(int row, float deltaTime, bool faceRight)
{
	m_CurrentImage.y = row;
	m_TotalTime += deltaTime;

	if (m_TotalTime >= m_SwitchTime)
	{
		m_TotalTime -= m_SwitchTime;
		m_CurrentImage.x++;

		if (m_CurrentImage.x >= m_ImageCount.x)
		{
			m_CurrentImage.x = 0;
		}
	}

	m_UvRect.top = m_CurrentImage.y * m_UvRect.height;

	if (faceRight)
	{
		m_UvRect.left = m_CurrentImage.x * m_UvRect.width;
		m_UvRect.width = abs(m_UvRect.width);
	}
	else
	{
		m_UvRect.left = (m_CurrentImage.x + 1) * abs(m_UvRect.width);
		m_UvRect.width = -abs(m_UvRect.width);
	}
}