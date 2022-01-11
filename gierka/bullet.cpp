#include "bullet.h"
#include "weapon.h"

bullet::bullet()
{
	bulletObject.setRadius(2);
	bulletObject.setFillColor(sf::Color::Black);
}

int bullet::giveDamage()
{
	return damage;
}
