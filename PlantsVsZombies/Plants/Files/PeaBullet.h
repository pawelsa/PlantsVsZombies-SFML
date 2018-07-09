#pragma once
#include <SFML/Graphics.hpp>
#include "Dimensions.h"
#include <iostream>

extern Textures *allTextures;

class PeaBullet {

	sf::CircleShape bullet;

	sf::Vector2f startPos;

public:

	PeaBullet(sf::Vector2i arenaPos) {

		bullet.setRadius(10);
		bullet.setTexture(allTextures->getTexture(Textures::BULLET));
		
		startPos = DIM::beginnigSpace + (sf::Vector2f) arenaPos * DIM::size;

		startPos.x += 0.5*DIM::size.x;
		startPos.y += 0.25*DIM::size.y;
		
		setStartPosition();
		
	}
	
	void display(sf::RenderWindow *window) {

		//std::cout << "Bullet x: " << bullet.getPosition().x << " y: " << bullet.getPosition().y << "\n";
		window->draw(bullet);
	}


	void move() {

		//bullet.setPosition(bullet.getPosition() + sf::Vector2f(5, 0));
		bullet.move(5, 0);
		restartIfIsTooFar();
	}

	sf::FloatRect returnFloatRect() {

		return bullet.getGlobalBounds();
	}

private:

	void restartIfIsTooFar() {

		if (bullet.getPosition().x - startPos.x >= 9 * DIM::size.x) {
			setStartPosition();
		}
	}

	void setStartPosition() {
		bullet.setPosition(startPos);
	}

};