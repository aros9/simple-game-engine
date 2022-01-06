#include "Engine.h"

void Engine::update(float dtAsSeconds)
{

    m_Player.update(dtAsSeconds);
    for (Bullet& bullet : m_Player.getBullets())
        bullet.move(dtAsSeconds);

    for (Platform& platform : platforms)
    {
        platform.getCollider().checkCollision(m_Player.getCollider(), m_Player.getDirection(), 1.0f);
        for (Bullet& bullet : m_Player.getBullets())
        {
            if (platform.getCollider().checkCollision(bullet.getCollider(), bullet.getDirection(), 1.0f) == true)
            {
                bullet.setCollision();
                printf("COLLISION DETECTED!\n");
            }
        }
    }
}