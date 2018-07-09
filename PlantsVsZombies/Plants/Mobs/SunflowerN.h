#pragma once
#include "Mob.h"
#include "C:\Users\Pawel\source\repos\PlantsVsZombies\Plants\AdditionalTools\Textures.h"
#include "C:\Users\Pawel\source\repos\PlantsVsZombies\Plants\AdditionalObjects\Sun.h"

extern Textures *allTextures;

class Sunflower : public Mob {

	Sun *sun;

public:

	Sunflower(sf::Vector2i arenaPos, Sun *sun) : Mob(3000, 0, arenaPos) {

		this->sun = sun;

		health = 70;

		rect.setTexture(allTextures->getTexture(Textures::SUNFLOWER));

		TAG = 2;

		lastTimeUsed = clock();

		attack();
	}

	int attack() {
		if (canAttack()) {

			lastTimeUsed = clock();
			sun->addSun(25);
		}
		return 0;
	}
};