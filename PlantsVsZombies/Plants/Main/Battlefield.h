#pragma once
#include "AdditionalTools\Dimensions.h"
#include "MobGroups\Arena.h"
#include "MobGroups\BunchOfZombies.h"
#include "AdditionalTools\CollisionDetector.h"
#include "C:\Users\Pawel\source\repos\PlantsVsZombies\Plants\AdditionalObjects\ChooseCharacter.h"

class Battlefield {

	Arena *arena;
	BunchOfZombies *bunchOfZombies;
	ChooseCharacter *chooseCharacter;
	Sun *sun;

	Arena::PlantType plantType;
	Point position;

	int wave = 0;
	const int MAX_WAVE = 5;



	void display(sf::RenderWindow *window) {
		arena->nextFrame(window);

		if (bunchOfZombies->displayAndCheckIfAllDied(window) && wave < MAX_WAVE) {
			delete bunchOfZombies;
			bunchOfZombies = new BunchOfZombies(wave);
			bunchOfZombies->displayAndCheckIfAllDied(window);
		}
		chooseCharacter->display(window);
	}

	void moveZombies() {
		bunchOfZombies->move();
	}

	void collisions() {

		std::vector<Mob*> plants;
		std::vector<Zombie*> zombies;

		std::vector<Zombie*>::iterator zombieIterator = zombies.begin();
		std::vector<Mob*>::iterator plantIterator = plants.begin();

		for (int i = 0; i < 5; i++) {
			plants = arena->returnRowOfPlants(i);
			zombies = bunchOfZombies->returnRowOfZombies(i);

			zombieIterator = zombies.begin();
			plantIterator = plants.begin();

			while (zombieIterator != zombies.end()) {
				(*zombieIterator)->setOnPlant(false);
				zombieIterator++;
			}

			while (plantIterator != plants.end() && zombies.size() > 0) {

				zombieIterator = zombies.begin();

				while (zombieIterator != zombies.end() && plants.size() > 0) {

					if (typeid(*(*plantIterator)) == typeid(Pea)) {

						Pea *pea = dynamic_cast<Pea*> (*plantIterator);
						if (CollisionDetector::testCollision(pea->returnFloatRect(), (*zombieIterator)->returnFloatRect())) {
							(*zombieIterator)->setOnPlant(true);
							int zombieDamage = (*zombieIterator)->attack();
							if (pea->wasHitAndCheckIfDied(zombieDamage)) {
								plantIterator = plants.erase(plantIterator);
								if ((*zombieIterator) != NULL) {
									(*zombieIterator)->setOnPlant(false);
								}
							}
						}
						if (CollisionDetector::testCollision(pea->returnBulletFloatRect(), (*zombieIterator)->returnFloatRect())) {

							int damage = pea->attack();
							if ((*zombieIterator)->wasHitAndCheckIfDied(damage, false)) {
								zombieIterator = zombies.erase(zombieIterator);
							}
							pea->removeBullet();
						}

						(*plantIterator) = pea;
					}
					else if (CollisionDetector::testCollision((*plantIterator)->returnFloatRect(), (*zombieIterator)->returnFloatRect())) {
						int damage = (*plantIterator)->attack();
						int zombieDamage = 0;
						if ((*zombieIterator)->wasHitAndCheckIfDied(damage)) {
							zombieIterator = zombies.erase(zombieIterator);
						}
						else {
							zombieDamage = (*zombieIterator)->attack();
						}
						if (typeid(*(*plantIterator)) == typeid(Potato)) {
							zombieDamage = -101;
						}
						if ((*plantIterator)->wasHitAndCheckIfDied(zombieDamage)) {
							plantIterator = plants.erase(plantIterator);
							if ((*zombieIterator) != NULL) {
								(*zombieIterator)->setOnPlant(false);
							}
						}
					}
					if (zombies.size() <= 1) {
						break;
					}
					zombieIterator++;
				}
				if (plants.size() <= 1) {
					break;
				}
				plantIterator++;
			}

			arena->updatePlantsRow(plants, i);
			bunchOfZombies->updateZombiesRow(zombies, i);
		}
	}

public:

	Battlefield() {
		sun = new Sun();
		arena = new Arena(sun);
		bunchOfZombies = new BunchOfZombies(wave);
		chooseCharacter = new ChooseCharacter(sun);

		plantType = Arena::NONE;
		position = Point(-1, -1);
	}

	void nextFrame(sf::RenderWindow *window) {
		moveZombies();
		display(window);
		collisions();
	}

	void mouseButtonPressed(sf::RenderWindow *window) {

		position = CollisionDetector::checkIfMouseInsideChoose(window);
		Point onArena = CollisionDetector::checkIfMouseInsideField(window);
		plantType = onArena == Point(-1,-1) ? chooseCharacter->returnPlantTypeIfPossible(position) : plantType;
		if (plantType == Arena::NONE && onArena == Point(-1, -1)) {
			chooseCharacter->clearSelection();
			position = Point(-1, -1);
		}
	}

	void mouseButtonReleased(sf::RenderWindow *window) {

		Point positionOnArena = CollisionDetector::checkIfMouseInsideField(window);

		if (plantType != Arena::PlantType::NONE && positionOnArena != Point(-1, -1)) {
			if (arena->createMob(plantType, positionOnArena)) {
				int costOfPlanting = chooseCharacter->returnCost(plantType);
				sun->reduceSun(costOfPlanting);

				plantType = Arena::NONE;
				position = Point(-1, -1);
			}
		}

	}

};
