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

	HUD();
	void hudDisplay(sf::RenderWindow &window, int x, int y, weapon weapon, bool isLoaded, int hp, int hpMax, int whichWeapon);
};

