#include "weapon.h"
#include <iostream>

weapon::weapon()
{
	weaponTex.loadFromFile("Textures/bron.png");
	weaponBody.setTexture(weaponTex);
	weaponBody.setPosition(500, 200);
	weaponBody.setOrigin(14, 4);
}
sf::Sprite weapon::getWeapon()
{
	return weaponBody;
}
void weapon::updatePos(sf::Vector2f pos, sf::Vector2f mousePos)
{
	weaponBody.setPosition(pos.x + 50, pos.y + 50);

	sf::Vector2f weaponPos = weaponBody.getPosition();

	const float Pi = 3.14159265359;

	float dX = mousePos.x - weaponPos.x;
	float dY = mousePos.y - weaponPos.y;

	float deg = (atan2(dY, dX)  * 180 / Pi) - 90;

	if(mousePos.x - weaponPos.x < 0) weaponBody.setScale(sf::Vector2f(1, -1));
	else weaponBody.setScale(sf::Vector2f(1, 1));

	weaponBody.setRotation(deg + 90);

	std::cout << "pozycja broni " << pos.x << " " << pos.y << " Pozycja kursora" << mousePos.x << " " << mousePos.y << std::endl;
}
