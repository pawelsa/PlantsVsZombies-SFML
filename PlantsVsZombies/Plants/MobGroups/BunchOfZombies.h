#pragma once
#include "Mobs/Zombie.h"
#include <ctime>


class BunchOfZombies
{

	std::vector<Zombie*> zombie[5];

	const int amountOfZombiesDuringWave = 5;

public:

	BunchOfZombies(int wave) {

		srand(time(0));

		for (int i = 0; i < amountOfZombiesDuringWave + (wave * 2); i++) {

			int randomRow = rand() % 5;;
			zombie[randomRow].push_back(new Zombie(randomRow, zombie[randomRow].size()));
		}
	}

	bool displayAndCheckIfAllDied(sf::RenderWindow *window) {

		bool allDied = true;

		for (int i = 0; i < 5; i++) {
			
			if (zombie[i].size() > 0) {
				for (int j = 0; j < zombie[i].size(); j++) {

					zombie[i].at(j)->display(window);
				}
				allDied = false;
			}
		}
		return allDied;
	}

	void move() {

		std::vector<Zombie*>::iterator zombieIterator;

		for (int i = 0; i < 5; i++) {
			zombieIterator = zombie[i].begin();
			
			while (zombieIterator != zombie[i].end()) {
				(*zombieIterator)->move();
				zombieIterator++;
			}
		}
	}

	std::vector<Zombie*> returnRowOfZombies(int row) {		
		return zombie[row];
	}

	void updateZombiesRow(std::vector<Zombie*> zombiesRow, int row) {
		zombie[row] = zombiesRow;
	}

};