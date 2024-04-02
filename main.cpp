#include <SFML/Graphics.hpp>
#include "seaweed.h"
#include "plancton.h"
#include "mussel.h"
#include "config.h"

#include <vector>


#include <iostream>


int main() {
    sf::RenderWindow window(sf::VideoMode(config::width, config::height), "Aquarium");
    srand(time(0));
    //seaweed Seaweed(sf::Vector2f(100.f, 90.f));
    plancton Plancton(sf::Vector2f(500, 500));
    //mussel Mussel(sf::Vector2f(10, 680));

    //std::vector<mussel*> mussels;

//    for (int i = 0; i < config::numberOfMussels; ++i) {
//        mussel* pa = new mussel;
//
//        mussels.push_back(pa);
//    }
    sf::Clock clock;
    std::cout << "TYT";
    while (window.isOpen()) {
        sf::Event event;
        sf::Time elapsed = clock.restart();
        std::cout << elapsed.asSeconds() << std::endl;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
                window.close();
        }

        Plancton.move(elapsed);

        window.clear(config::background);

        //for (auto& mussel : mussels) mussel->draw(window);
        Plancton.draw(window);
        //Seaweed.draw(window);
        //Mussel.draw(window);

        window.display();
    }

    return 0;
}