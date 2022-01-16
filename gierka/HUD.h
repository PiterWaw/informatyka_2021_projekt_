#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>
#include "weapon.h"

class HUD
{
public:
	sf::Sprite ammoBox;
	sf::Texture ammoBoxTex;
	sf::Text ammoCount;

	sf::Sprite hpBox;
	sf::Texture hpBoxTex;
	sf::Text hpCount;

	sf::Sprite weaponBox;
	sf::Texture weaponBoxTex;
	sf::Text weaponNumber1;
	sf::Text weaponNumber2;
	sf::Text weaponNumber3;

	sf::Font font;
	std::string ammoDisplay;
	std::string hpDisplay;

	sf::Sprite m4a4Box;
	sf::Texture m4a4BoxTex;
	sf::Sprite shotgunBox;
	sf::Texture shotgunBoxTex;
	sf::Sprite minigunBox;
	sf::Texture minigunBoxTex;
	sf::RectangleShape chosenWeapon;

	sf::Sprite zombieBox;
	sf::Texture zombieBoxTex;
	sf::Text zombieCount;
	std::string zombieDisplay;

	sf::Text waveInfo;
	std::string waveInfoString;

	sf::Text nickBox;

	HUD();
	void hudDisplay(sf::RenderWindow &window, int x, int y, weapon weapon, bool isLoaded, int hp, int hpMax, int whichWeapon, int howManyZombie, int whichWave, bool shotgun, bool minigun, std::string nick, int xP, int yP);
};

