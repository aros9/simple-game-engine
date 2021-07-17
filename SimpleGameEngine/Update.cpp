#include "Engine.h"

void Engine::update(float dtAsSeconds)
{

    m_Player.update(dtAsSeconds);

    for (Platform& platform : platforms)
        platform.getCollider().checkCollision(m_Player.getCollider(), m_Player.getDirection(), 1.0f);
}