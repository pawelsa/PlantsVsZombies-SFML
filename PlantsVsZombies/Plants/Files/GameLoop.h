#pragma once
#include <SFML\Graphics.hpp>
#include "Files/Textures.h"
Textures *allTextures = new Textures();
#include "Battlefield.h"
#include "Files/Dimensions.h"

class GameLoop {
	
	sf::RenderWindow *window;

public:

	GameLoop() {

		window = new sf::RenderWindow(sf::VideoMode(DIM::currentSize.x, DIM::currentSize.y), "Plants Vs Zombies");
		window->setFramerateLimit(60);
	}

	void main() {

		Battlefield *battlefield = new Battlefield();

		while (window->isOpen())
		{
			sf::Event event;

			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					window->close();
				}

				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
					battlefield->mouseButtonPressed(window);
				}

				if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right) {
					battlefield->mouseButtonReleased(window);
				}
			}

			window->clear();

			battlefield->nextFrame(window);

			window->display();
		}
	}
};