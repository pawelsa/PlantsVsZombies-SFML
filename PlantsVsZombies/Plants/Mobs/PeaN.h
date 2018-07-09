#pragma once
#include "Mob.h"
#include "C:\Users\Pawel\source\repos\PlantsVsZombies\Plants\AdditionalTools\Dimensions.h"
#include "PeaBullet.h"

extern Textures *allTextures;



class Pea : public Mob {

	PeaBullet *bullet;

public:

	Pea(sf::Vector2i arenaPos) : Mob(2500, -26, arenaPos) {

		health = 100;

		rect.setTexture(allTextures->getTexture(Textures::PEA));

		TAG = 1;

		bullet = NULL;

		lastTimeUsed = clock();

		attack();
	}

	void display(sf::RenderWindow *window) {

		window->draw(rect);
		if (bullet != NULL)
			bullet->display(window);
	}


	int attack() {
		
		if (bullet == NULL && canAttack()) {	// was ACTIVATE_TIME / 2

			bullet = new PeaBullet(arenaPos);
			lastTimeUsed = clock();
			return DAMAGE;
		}
		else if (bullet!=NULL)  {

			bullet->move();
			return DAMAGE;
		}
		return 0;

	}

	~Pea() {

		if (bullet != NULL) {
			delete(bullet);
			bullet = NULL;
		}
	}


	sf::FloatRect returnBulletFloatRect() {

		if (bullet != NULL)
			return bullet->returnFloatRect();

		return sf::FloatRect();
	}

	void removeBullet() {
		if (bullet != NULL) {
			delete(bullet);
			bullet = NULL;
		}
	}


};