#pragma once
#include <SFML/Graphics.hpp>


class bullet
{
private:

public:
	sf::CircleShape bulletObject;
	sf::Vector2f currentVelocity;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
	float bulletSpeed = 10;

	int damage;

	int giveDamage();
	bullet();
};

