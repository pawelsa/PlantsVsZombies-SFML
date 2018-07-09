#pragma once
#include <SFML\Graphics.hpp>
#include "C:\Users\Pawel\source\repos\PlantsVsZombies\Plants\AdditionalTools\Textures.h"

extern sf::RenderWindow window;
extern Textures *allTextures;


class Zombie : public Mob {

	bool onPlant = false;

public:

	Zombie(int i, int amount) : Mob(1500, -26, sf::Vector2i()) {

		health = 100;

		rect.setSize(DIM::size);
		rect.setTexture(allTextures->getTexture(Textures::ZOMBIE));

		sf::Vector2i positionOnArena(9, i);

		int rangeOfDistanceBehindPrewiousZombie = rand() % 15 + 5;

		sf::Vector2f positionInGame = DIM::beginnigSpace + (sf::Vector2f) positionOnArena * DIM::size;
		positionInGame.x += amount * rangeOfDistanceBehindPrewiousZombie;

		rect.setPosition(positionInGame);
	}
	
	bool operator <(const Zombie & otherZombie) const {
		return rect.getPosition().x < otherZombie.rect.getPosition().x;
	}

	void move() {

		if (!onPlant) {
			rect.move(-0.1, 0);
		}
	}
	
	bool wasHitAndCheckIfDied(int damage, bool steppedOnPlant = true) {

		setOnPlant(steppedOnPlant);

		health += damage;

		if (health < 0)
			return true;

		return false;
	}

	void setOnPlant(bool is) {
		onPlant = is;
	}

	bool isOnPlant() {
		return onPlant;
	}

};