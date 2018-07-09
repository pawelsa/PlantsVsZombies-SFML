#pragma once
#include "PeaN.h"
#include "SunflowerN.h"
#include "NutN.h"
#include "PotatoN.h"
#include "Dimensions.h"


class Field {
private:

	sf::RectangleShape **rect;

	sf::RectangleShape battlefield;

	sf::Vector2i size;

	void createFrame() {

		battlefield.setSize(sf::Vector2f((size.x * DIM::size.x), (size.y * DIM::size.y)));
		battlefield.setFillColor(sf::Color::Black);
		battlefield.setOutlineThickness(5);
		battlefield.setOutlineColor(sf::Color::White);
		if (size.y == 1) {
			battlefield.setPosition(DIM::chooseCharacterPosition);
		}
		else {
			battlefield.setPosition(DIM::beginnigSpace);
		}
	}

	void createFields(int x_, int y_) {


		bool fieldColorType = true;
		sf::Texture *texture;

		rect = new sf::RectangleShape*[y_];
		for (int i = 0; i < y_; i++) {
			rect[i] = new sf::RectangleShape[x_];
		}


		for (int y = 0; y < y_; y++) {
			for (int x = 0; x < x_; x++) {

				texture = fieldColorType ? allTextures->getTexture(Textures::GRASS_LIGHT) : allTextures->getTexture(Textures::GRASS_DARK);
				sf::RectangleShape rectangle = createField(texture, sf::Vector2i(x, y), size.y == 1);
				rect[y][x] = rectangle;
				fieldColorType = !fieldColorType;
			}
		}
	}

	sf::RectangleShape createField(const sf::Texture *texture, sf::Vector2i positionOnArena, bool chooseCharacter=false) const {

		sf::RectangleShape rect = sf::RectangleShape();

		rect.setSize(DIM::size);

		rect.setTexture(texture);

		sf::Vector2f positionInGame = (chooseCharacter ? DIM::chooseCharacterPosition : DIM::beginnigSpace) + (sf::Vector2f) positionOnArena * DIM::size;
		rect.setPosition(positionInGame);

		return rect;
	}

public:

	Field(int x, int y) {
		size = sf::Vector2i(x, y);
		createFrame();
		createFields(x,y);
	}

	void display(sf::RenderWindow *window) {

		window->draw(battlefield);

		for (int y = 0; y < size.y; y++)
			for (int x = 0; x < size.x; x++)
				window->draw(rect[y][x]);
	}

	void setAlpha(double percent, sf::Vector2i position) {

		rect[position.y][position.x].setScale(sf::Vector2f(percent, percent));
	}

};