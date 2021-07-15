#include "Engine.h"

void Engine::update(float dtAsSeconds)
{

    m_Player->update(dtAsSeconds);
    m_Platform.getCollider().checkCollision(m_Player, m_Player->getDirection(), 0.0f);
    m_Floor.getCollider().checkCollision(m_Player, m_Player->getDirection(), 1.0f);
}