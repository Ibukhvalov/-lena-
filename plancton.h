#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "config.h"

int radius = 50;

class plancton
{
public:
    plancton(const sf::Vector2f& position) : position(position), obj(radius), speed(100)
    {
        setRandomVelocity();
        obj.setOrigin(radius, radius);
        //planctonTexture.loadFromFile("images/plancton.png");
        //sprite.setTexture(planctonTexture);
        //sprite.scale(sf::Vector2f(0.15, 0.15));
        obj.setPosition(position);
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(obj);
    }

    void normalizeVelocity() {
        velocity /= powf((pow(velocity.x, 2) + pow(velocity.y, 2)), 0.5);
    }

    void setRandomVelocity() {
        velocity = { rand() % 100 - 50, rand() % 100 - 50 };
        normalizeVelocity();
    }

    void move(sf::Time elapsed)
    {
        if (position.x <= 0 + radius || position.x > config::width - radius) {
            velocity.x *= -1;
        }
        if (position.y <= 0 + radius || position.y > config::height - radius)
            velocity.y *= -1;

        //if (position.x < 0 or position.x>1280 - 100) xPlanctonVelocity *= -1;
        //if (position.y < 0 or position.y>720 - 100) yPlanctonVelocity *= -1;

        //position.x += xPlanctonVelocity;
        //position.y += yPlanctonVelocity;
        position += velocity * elapsed.asSeconds() * speed;
        obj.setPosition(position);
        //sprite.setPosition(position);
    }

private:
    sf::CircleShape obj;
    //sf::Texture planctonTexture;
    //sf::Sprite sprite;
    float speed;
    sf::Vector2f position;
    sf::Vector2f velocity; 
};