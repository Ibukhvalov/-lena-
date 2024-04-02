#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class seaweed
{
public:
    seaweed(const sf::Vector2f& position): position(position)
    {
        if (!seaweedTexture.loadFromFile("images/seaweed.png"))
            std::cout << "ALARM";
        sprite.setTexture(seaweedTexture);
        sprite.setPosition(position);
        sprite.scale(1.15, 1.15);
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(sprite);
    }

private:
    sf::Texture seaweedTexture;
    sf::Sprite sprite;
    sf::Vector2f position;
};