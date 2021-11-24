#pragma once
#include <SFML/Graphics.hpp>

class weapon
{
public:
	sf::Vector2f pos;
	sf::Sprite weaponBody;
	sf::Texture weaponTex;
	sf::Sprite getWeapon();
	weapon();
	void updatePos(sf::Vector2f pos, sf::Vector2f mousePos);
};


