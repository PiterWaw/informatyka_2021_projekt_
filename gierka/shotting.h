#pragma once
#include "bullet.h"
#include "mapa.h"
#include "weapon.h"
#include <iostream>

class shotting
{
public:
	bullet b1;
	std::vector<bullet> bullets;
	void shottingUpdate(sf::RenderWindow& window, sf::Vector2f mousePos, sf::Vector2f weaponPos, mapa mapa, weapon& weapon);
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

