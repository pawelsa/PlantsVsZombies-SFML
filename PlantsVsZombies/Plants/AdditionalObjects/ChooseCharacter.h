#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include "AdditionalObjects/Field.h"
#include "Mobs/Mob.h"
#include "AdditionalTools/Textures.h"
#include "AdditionalObjects/LoadingRectangular.h"
#include "AdditionalObjects/Sun.h"

extern Textures *allTextures;

class ChooseCharacter{
	
	Field *frame;
	LoadingRectangular *rect[4];
	Sun *sun;

	const sf::Texture *mobTextures[4] = { 
		allTextures->getTexture(Textures::PEA),
		allTextures->getTexture(Textures::SUNFLOWER),
		allTextures->getTexture(Textures::NUT),
		allTextures->getTexture(Textures::POTATO)
		};

	
	const int cost[4] = { 100, 50, 150, 200 };
	const int waitTime[4] = { 2500, 1500, 6000,3000 };
	int lastTimeUsed[4];



	bool timeCondition(int pos) {
		return clock() - lastTimeUsed[pos] >= waitTime[pos];
	}

	bool sunCondition(int pos) {
		return sun->getQuantity() >= cost[pos];
	}


public:
	
	ChooseCharacter(Sun *sun) {
		this->sun = sun;
		
		int time = clock();

		frame = new Field(4, 1);

		for (int i = 0; i < 4; i++) {

			sf::Vector2f position = DIM::chooseCharacterPosition;
			position.x += i * DIM::size.x;

			rect[i] = new LoadingRectangular(mobTextures[i], position);

			lastTimeUsed[i] = time;
		}

	}

	void display(sf::RenderWindow *window) {

		double actualTime = clock();

		frame->display(window);
		for (int i = 0; i < 4; i++) {

			double percent = actualTime - lastTimeUsed[i] > waitTime[i] ? 100 : (actualTime - lastTimeUsed[i]) / waitTime[i] * 100;
			if (percent < 101) {
				rect[i]->setPercent(percent);
			}

			rect[i]->display(window);
		}
	}

	Arena::PlantType returnPlantTypeIfPossible(Point position) {


		if (position != Point(-1, -1) && 
			timeCondition(position.y) && 
			sunCondition(position.y)) {

			switch (position.y) {
			case 0:
				rect[position.y]->setChosen(true);
				return Arena::PlantType::PEA;
			case 1:
				rect[position.y]->setChosen(true);
				return Arena::PlantType::SUNFLOWER;
			case 2:
				rect[position.y]->setChosen(true);
				return Arena::PlantType::NUT;
			case 3:
				rect[position.y]->setChosen(true);
				return Arena::PlantType::POTATO;
			}
		}
		return Arena::PlantType::NONE;

	}

	int returnCost(Arena::PlantType type) {
		rect[type]->setChosen(false);
		return cost[type];
	}

	void clearSelection() {
		for (int i = 0; i < 4; i++) {
			rect[i]->setChosen(false);
		}
	}

};