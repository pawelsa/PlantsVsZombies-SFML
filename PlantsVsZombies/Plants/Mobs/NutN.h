#pragma once
#include "Mob.h"
#include "C:\Users\Pawel\source\repos\PlantsVsZombies\Plants\AdditionalTools\Textures.h"
extern Textures *allTextures;


class Nut : public Mob {

public:

	Nut(sf::Vector2i arenaPos) : Mob(0, 0, arenaPos) {

		health = 1500;

		rect.setTexture(allTextures->getTexture(Textures::NUT));

		TAG = 3;

		lastTimeUsed = clock();
	}

};