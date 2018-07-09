#pragma once
#include <SFML/Graphics.hpp>

typedef sf::Vector2i Point;

namespace DIM {


	sf::Vector2i defaultSize = sf::Vector2i(1700, 800);
	float scale = 1;
	sf::Vector2i currentSize = sf::Vector2i(defaultSize.x*scale, defaultSize.y*scale);

	sf::Vector2f size = sf::Vector2f(60, 80)*scale;
	sf::Vector2f beginnigSpace = sf::Vector2f(80, 160)*scale;
	sf::Vector2f chooseCharacterPosition = sf::Vector2f(80, 40);

	static sf::Vector2f percentageSize(int percent) {

		double percentageHeight = (percent * DIM::size.y)/100;

		return sf::Vector2f(size.x, percentageHeight);
	}

}