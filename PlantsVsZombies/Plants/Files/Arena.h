#pragma once
#include <SFML/Graphics.hpp>
#include "Dimensions.h"
#include "CollisionDetector.h"
#include "Sun.h"
#include "Field.h"
#include "Textures.h"
#include "Mob.h"
#include "NutN.h"
#include "PeaN.h"
#include "PotatoN.h"
#include "SunflowerN.h"

extern Textures *allTextures;

class Arena {

	Field *field;
	Mob *plants[5][9];
	Sun *sun;

	void setPlantFieldToNULL() {

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				
				plants[i][j] = NULL;
			}
		}
	}

	void displayPlantsAndAttack(sf::RenderWindow *window) {

		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 9; x++) {
				if (plants[y][x] != NULL) {
					plants[y][x]->display(window);
					plants[y][x]->attack();
				}
			}
		}
	}

	void deleteMob(Point position) {
		delete plants[position.x][position.y];
		plants[position.x][position.y] = NULL;
	}
	
public:

	static enum PlantType {
		PEA, SUNFLOWER, NUT, POTATO, NONE
	};
	
	Arena(Sun *sun) {
		
		field = new Field(9, 5);
		setPlantFieldToNULL();
		this->sun = sun;
	}

	void nextFrame(sf::RenderWindow *window) {
		field->display(window);
		sun->display(window);
		displayPlantsAndAttack(window);
	}

	bool createMob(PlantType type, Point position) {

		if (!plants[position.y][position.x] == NULL)
			return false;

		switch (type) {

		case PEA: {

			plants[position.y][position.x] = new Pea(position);
			return true;
		}
		case SUNFLOWER: {

			plants[position.y][position.x] = new Sunflower(position, sun);
			return true;
		}
		case NUT: {

			plants[position.y][position.x] = new Nut(position);
			return true;
		}
		case POTATO: {

			plants[position.y][position.x] = new Potato(position);
			return true;
		}
		}
		return false;
	}

	std::vector<Mob*> returnRowOfPlants(int row) {
		std::vector<Mob*> takenRow;
		for (int x = 0; x < 9; x++) {
			if (plants[row][x] != NULL) {
				takenRow.push_back(plants[row][x]);
			}
		}
		return takenRow;
	}

	void updatePlantsRow(std::vector<Mob*> plantsRow, int row) {

		for (int x = 0; x < 9; x++) {
			plants[row][x] = NULL;
		}
		for (Mob *plant : plantsRow) {
			Point position = CollisionDetector::returnPositionOnArena(plant->returnPosition());
			plants[position.y][position.x] = plant;
		}
			
	}

	sf::FloatRect getBoundsOfMob(Point position) {
		if (plants != NULL && plants[position.y][position.x] != NULL)
			return plants[position.y][position.x]->returnFloatRect();
		return sf::FloatRect();
	}
	
	bool isThereMob(Point position) {
		return plants[position.x][position.y] == NULL ? false : true;
	}
	

};
