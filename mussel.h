#pragma once
#include <SFML/Graphics.hpp>

class mussel {
public:
	mussel() : mussel( sf::Vector2f(rand() % 1280, 640 + rand()%40 )) {};

	mussel(const sf::Vector2f& position): position(position) {
		musselTexture.loadFromFile("images/mussel.png");
		sprite.setTexture(musselTexture);
		sprite.setPosition(position);
		sprite.scale(0.1, 0.1);
	}
	void draw(sf::RenderWindow& window)
	{
		window.draw(sprite);
	}
private:
	sf::Texture musselTexture;
	sf::Sprite sprite;
	sf::Vector2f position;
};