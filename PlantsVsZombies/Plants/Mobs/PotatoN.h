#pragma once
#include "Mob.h"
#include "C:\Users\Pawel\source\repos\PlantsVsZombies\Plants\AdditionalTools\Textures.h"
extern Textures *allTextures;


class Potato : public Mob {

public:

	Potato(sf::Vector2i arenaPos) : Mob(5000, -90, arenaPos) {

		health = 100;

		rect.setTexture(allTextures->getTexture(Textures::POTATO_NOT));

		TAG = 4;

		lastTimeUsed = clock();

		attack();
	}

	int attack() {

		if (canAttack()) {

			rect.setTexture(allTextures->getTexture(Textures::POTATO));
			lastTimeUsed = clock();
			DAMAGE = -90;
		}
		return DAMAGE;
	}


};
