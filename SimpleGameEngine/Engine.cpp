#include "Engine.h"

Engine::Engine()
{
    // Get the screen resolution and create an SFML window and View
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;


    m_Window.create(sf::VideoMode(resolution.x, resolution.y), "Simple Game", sf::Style::Fullscreen);

    // Load the background into the texture
    m_BackgroundTexture.loadFromFile("src/background.jpg");

    // Associate the sprite with the texture
    m_BackgroundSprite.setTexture(m_BackgroundTexture);

    platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 20.0f), sf::Vector2f(500.0f, resolution.y - 150.0f))); // platorm1
    platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 20.0f), sf::Vector2f(1000.0f, resolution.y - 300.0f))); // platform2
    platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1500.0f, resolution.y - 150.0f))); // platform3
    platforms.push_back(Platform(nullptr, sf::Vector2f(1920.0f, 100.0f), sf::Vector2f(resolution.x / 2.0f, resolution.y))); // floor

}

void Engine::start()
{
    // Timing
    sf::Clock clock;

    while (m_Window.isOpen())
    {
        // Restart the clock and save the elapsed time into dt
        sf::Time dt = clock.restart();

        // Make a fraction from the delta time
        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
}