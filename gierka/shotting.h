#pragma once

#include "SFML/Audio.hpp"
#include "bullet.h"
#include "mapa.h"
#include "weapon.h"
#include <iostream>

class shotting
{
public:
	sf::SoundBuffer buffer1, buffer2, buffer3;
	sf::Sound sound1, sound2, sound3;
	sf::SoundBuffer sb, rb, mb;
	sf::Sound s, r, m;
	bullet b1;
	std::vector<bullet> bullets;
	void shottingUpdate(sf::RenderWindow& window, sf::Vector2f mousePos, sf::Vector2f weaponPos, mapa mapa, weapon& weapon, int whichWeapon);
	sf::Clock cooldown;
	sf::Clock reloadCooldown;

	int maxAmmo = 30;
	int ammo = maxAmmo;
	int damage = 1;
	bool isLoaded = true;
	int lastShot = 1;
	int lastShot2 = -1;
	bool isFirstShot = true;

	shotting();
	void bulletCollision(mapa mapa);
	int updateHowMuchAmmo(weapon weapon);
	int isFire();
};

