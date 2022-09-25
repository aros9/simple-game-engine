#include "../inc/Collider.hpp"


Collider::Collider(sf::RectangleShape& body)
	:m_Body(body)
{

}

bool Collider::checkCollision(Collider* collider, sf::Vector2f& direction, float push)
{
	sf::Vector2f otherPosition = collider->GetPosition();
	sf::Vector2f otherHalfSize = collider->GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				//Left collision
				Move(intersectX * (1.0f - push), 0.0f);
				collider->Move(-intersectX * push, 0.0f);

				direction.x = 1.0f;
				//printf("Left collision\n");
			}
			else
			{
				//Right collision
				Move(-intersectX * (1.0f - push), 0.0f);
				collider->Move(intersectX * push, 0.0f);

				direction.x = -1.0f;
				//printf("Right collision\n");
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				//Top collision
				Move(0.0f, intersectY * (1.0f - push));
				collider->Move(0.0f, -intersectY * push);

				direction.y = 1.0f;
				//printf("Top collision\n");
			}
			else
			{
				//Bottom collision
				Move(0.0f, -intersectY * (1.0f - push));
				collider->Move(0.0f, intersectY * push);

				direction.y = -1.0f;
				//printf("Bottom collision\n");
			}
		}

		return true;
	}

	return false;
}