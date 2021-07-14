#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h";
#include "Platform.h"

class Engine
{
private:

    // A regular RenderWindow
    sf::RenderWindow m_Window;

    // Declare a sprite and a Texture for the background
    sf::Sprite m_BackgroundSprite;
    sf::Texture m_BackgroundTexture;

    Player m_Player;

    Platform m_Platform;

    Platform m_Floor;

    void input();
    void update(float dtAsSeconds);
    void draw();

public:
    // The Engine constructor
    Engine();


    // start will call all the private functions
    void start();
};