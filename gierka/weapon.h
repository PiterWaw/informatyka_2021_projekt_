#pragma once
#include <SFML/Graphics.hpp>

class weapon
{
public:
	sf::Vector2f pos;
	sf::Sprite weaponBody;
	sf::Texture weaponTex;
	sf::Texture weaponTex2;
	sf::Texture weaponTex3;
	sf::Sprite getWeapon();

	int maxAmmo = 30;
	int ammo = maxAmmo;
	int damage = 1;
	int fireRate = 1;
	bool isLoaded = true;

	

	weapon();
	void updatePos(sf::Vector2f pos, sf::Vector2f mousePos);
	void changeWeapon(int whichWeapon);

	void changeAmmo(int amount) { ammo -= amount; }
	int howMuchAmmo() { return maxAmmo; }
};


