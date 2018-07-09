#pragma once
#include <SFML/Graphics.hpp>
#include "Dimensions.h"

class CollisionDetector {

public:

	static bool testCollision(sf::FloatRect field, sf::FloatRect zombie) {

		if (field.intersects(zombie)) {

			return true;
		}

		return false;
	}

	static sf::Vector2i returnPositionOnArena(sf::Vector2f position) {

		sf::Vector2i positionOnArena = (sf::Vector2i) (position - DIM::beginnigSpace);
		positionOnArena = positionOnArena / (sf::Vector2i) DIM::size;

		return positionOnArena;
	}

	//sf::Vector2i checkIfMouseInsideField() {

	//	int mouseX = sf::Mouse::getPosition(window).x - marginLeft - size.x;
	//	int mouseY = sf::Mouse::getPosition(window).y - marginAbove;


	//	int X = mouseX / size.x;
	//	int Y = mouseY / size.y;


	//	if ((X < 4 && Y < 1) && (mouseX >= 0 && mouseY >= 0))
	//		return sf::Vector2i(Y, X);		//	 X is in our interest


	//	return sf::Vector2i(-1, -1);
	//}

	static Point checkIfMouseInsideChoose(sf::RenderWindow *window) {

		sf::Vector2f mouse = (sf::Vector2f) sf::Mouse::getPosition(*window) - DIM::chooseCharacterPosition;
		sf::Vector2f pos = mouse / DIM::size;

		if ((pos.x < 4 && pos.y < 1) && (mouse.x >= 0 && mouse.y >= 0))
			return Point(pos.y,pos.x);

		return Point(-1, -1);
	}

	static Point checkIfMouseInsideField(sf::RenderWindow *window) {

		sf::Vector2f mouse = (sf::Vector2f) sf::Mouse::getPosition(*window) - DIM::beginnigSpace;
		sf::Vector2f pos = mouse / DIM::size;

		if ((pos.x < 9 && pos.y < 5) && (mouse.x >= 0 && mouse.y >= 0))
			return Point(pos.x, pos.y);

		return Point(-1, -1);
	}
};
