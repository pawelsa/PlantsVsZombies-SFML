#pragma once
#include "C:\Users\Pawel\source\repos\PlantsVsZombies\Plants\AdditionalTools\Dimensions.h"
#include <iostream>


class Mob {
protected:

	int health;
	int TAG;
	int lastTimeUsed;
	const int ACTIVATE_TIME;
	int DAMAGE;
	sf::RectangleShape rect;
	sf::Vector2i arenaPos;

	bool canAttack() {
		int currentTime = clock();
		return currentTime - lastTimeUsed > ACTIVATE_TIME;
	}


public:

	Mob() : ACTIVATE_TIME(0), DAMAGE(0) {

		rect.setSize(DIM::size);
	}

	Mob(int ACTIVATE_TIME, int DAMAGE, Point position) : ACTIVATE_TIME(ACTIVATE_TIME), DAMAGE(DAMAGE) {

		rect.setSize(DIM::size);
		sf::Vector2f positionOnArena = DIM::beginnigSpace + (sf::Vector2f) position * DIM::size;
		arenaPos = position;
		rect.setPosition(positionOnArena);
	}

	virtual int attack() {
		if (canAttack()) {
			lastTimeUsed = clock();
			return DAMAGE;
		}
		return 0;
	}

	virtual bool wasHitAndCheckIfDied(int damage) {

		health += damage;

		if (health < 0)
			return true;
		return false;
	}

	virtual void move() {}

	virtual void display(sf::RenderWindow *window) {
		window->draw(rect);
	}

	virtual sf::FloatRect returnFloatRect() {
		return rect.getGlobalBounds();
	}

	virtual sf::Vector2f returnPosition(){
		return rect.getPosition();
	}

};