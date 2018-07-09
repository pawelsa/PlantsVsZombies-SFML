#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Textures {

	sf::Texture *peaTexture;
	sf::Texture *nutTexture;
	sf::Texture *sunflowerTexture;
	sf::Texture *potatoNotActivatedTexture;
	sf::Texture *potatoActivatedTexture;

	sf::Texture *grassLight;
	sf::Texture *grassDark;

	sf::Texture *zombieTexture;

	sf::Texture *bulletTexture;


public:
	
	static enum TextureT { 
		PEA, NUT, SUNFLOWER, POTATO, POTATO_NOT, GRASS_DARK, GRASS_LIGHT, ZOMBIE, BULLET 
	};

	Textures() {

		try {
			peaTexture = new sf::Texture();
			nutTexture = new sf::Texture();
			sunflowerTexture = new sf::Texture();
			potatoActivatedTexture = new sf::Texture();
			potatoNotActivatedTexture = new sf::Texture();
			grassDark = new sf::Texture();;
			grassLight = new sf::Texture();
			zombieTexture = new sf::Texture();
			bulletTexture = new sf::Texture();
		}
		catch (char *e) {
			std::cout << e;
		}

		try {

			if (!peaTexture->loadFromFile("Textures/pea.png")) {

				throw "Couldn't load file";
			}
			if (!nutTexture->loadFromFile("Textures/nut.png")) {

				throw "Couldn't load file";
			}
			if (!sunflowerTexture->loadFromFile("Textures/sunflower.png")) {

				throw "Couldn't load file";
			}
			if (!potatoActivatedTexture->loadFromFile("Textures/potato.png")) {

				throw "Couldn't load file";
			}
			if (!potatoNotActivatedTexture->loadFromFile("Textures/NotPotato.png")) {

				throw "Couldn't load file";
			}
			if (!grassLight->loadFromFile("Textures/grassLight.png")) {

				throw "Couldn't load file";
			}
			if (!grassDark->loadFromFile("Textures/grassDark.png")) {

				throw "Couldn't load file";
			}
			if (!zombieTexture->loadFromFile("Textures/zombie.png")) {

				throw "Couldn't load file";
			}
			if (!bulletTexture->loadFromFile("Textures/bullet.png")) {

				throw "Couldn't load file";
			}


		}
		catch (char *e) {

			std::cout << e;
			exit(1);
		}
	}

	 sf::Texture *getTexture(TextureT WHICH) {

		switch (WHICH) {

			case 0: {
				return peaTexture;
			}
			case 1: {
				return nutTexture;
			}
			case 2: {
				return sunflowerTexture;
			}
			case 3: {
				return potatoNotActivatedTexture;
			}
			case 4: {
				return potatoActivatedTexture;
			}
			case 5: {
				return grassLight;
			}
			case 6: {
				return grassDark;
			}
			case 7: {
				return zombieTexture;
			}
			case 8: {
				return bulletTexture;
			}
		}
		return NULL;
	}


};
