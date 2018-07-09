#pragma once
#include <SFML/Graphics.hpp>
#include "Dimensions.h"
#include "Textures.h"

extern Textures *allTextures;

class LoadingRectangular {

	sf::RectangleShape plant;
	sf::RectangleShape loadingBar;

	bool isChosen = false;

public :

	LoadingRectangular(const sf::Texture *texture, sf::Vector2f position) {

		plant.setSize(DIM::size);
		loadingBar.setSize(DIM::size);

		plant.setTexture(texture);
		loadingBar.setFillColor(sf::Color(0,0,0,128));

		plant.setPosition(position);
		loadingBar.setPosition(position);

	}

	void setPercent(double percent) {

		if (!isChosen)
			loadingBar.setSize(DIM::percentageSize(100 - percent));
	}

	void display(sf::RenderWindow *window) {

		window->draw(plant);
		window->draw(loadingBar);
	}

	void setChosen(bool is) {
		isChosen = is;
		switch (isChosen)
		{
		case true:
			loadingBar.setSize(DIM::size);
			loadingBar.setFillColor(sf::Color(252, 202, 70, 128));
			break;
		case false:
			loadingBar.setSize(sf::Vector2f());
			loadingBar.setFillColor(sf::Color(0, 0, 0, 128));
			break;
		default:
			break;
		}
	}
	
};