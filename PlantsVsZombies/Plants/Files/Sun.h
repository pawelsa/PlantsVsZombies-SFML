#pragma once
#include <SFML/Graphics.hpp>
#include "Dimensions.h"


class Sun {

	sf::Text amountOfSun;
	sf::Font font;
	int quantity = 100;

public:

	Sun() {


		if (!font.loadFromFile("Font/arial.ttf"))
		{
			exit(1);
		}

		amountOfSun.setFont(font);
		amountOfSun.setPosition(sf::Vector2f(6 * DIM::beginnigSpace.x, DIM::beginnigSpace.y / 4));
		amountOfSun.setString(std::to_string(quantity));
		amountOfSun.setCharacterSize(50);
	}

	void display(sf::RenderWindow *window) {

		amountOfSun.setString(std::to_string(quantity));
		window->draw(amountOfSun);
	}

	void addSun(int quantity) {
		this->quantity += quantity;
	}

	int getQuantity() {
		return quantity;
	}

	void reduceSun(int quantity) {
		this->quantity -= quantity;
	}
};