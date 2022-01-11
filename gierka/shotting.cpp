#include "shotting.h"




void shotting::shottingUpdate(sf::RenderWindow& window, sf::Vector2f mousePos, sf::Vector2f weaponPos, mapa mapa, weapon& weapon)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (cooldown.getElapsedTime().asMilliseconds() > weapon.fireRate || isFirstShot == true) && weapon.isLoaded == true)
	{	
		isFirstShot = false;
		b1.aimDir = mousePos - weaponPos;
		b1.aimDirNorm = sf::Vector2f(b1.aimDir.x / sqrt(pow(b1.aimDir.x, 2) + pow(b1.aimDir.y, 2)), b1.aimDir.y / sqrt(pow(b1.aimDir.x, 2) + pow(b1.aimDir.y, 2)));

		b1.bulletObject.setPosition(sf::Vector2f(weaponPos.x ,weaponPos.y));

		b1.currentVelocity = b1.aimDirNorm * b1.bulletSpeed;

		bullets.push_back(bullet(b1));
		weapon.ammo--;
		cooldown.restart();

		if (weapon.ammo <= 0)
		{
			weapon.isLoaded = false;
			reloadCooldown.restart();
		}
	}
	else if (weapon.isLoaded == false && reloadCooldown.getElapsedTime().asMilliseconds() > 5000)
	{
		weapon.isLoaded = true;
		weapon.ammo = weapon.maxAmmo;
		std::cout << "roz\n";
	}

	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].bulletObject.move(bullets[i].currentVelocity);
	}

	for (size_t i = 0; i < bullets.size(); i++)
	{	
		window.draw(bullets[i].bulletObject);
	}

	//std::cout << bullets.size() << std::endl;
}

void shotting::bulletCollision(mapa mapa)
{
	for (int i = 0; i < mapa.sizeX; i++)
	{
		for (int j = 0; j < mapa.sizeY; j++)
		{
			if (mapa.mapaa[i][j] != 9 && mapa.mapaa[i][j] != 0)
			{
				sf::Vector2f tilePos;
				tilePos.x = i * 64;
				tilePos.y = j * 64;
				for (size_t i = 0; i < bullets.size(); i++)
				{
					sf::Vector2f pos = bullets[i].bulletObject.getPosition();
					int x = pos.x;
					int y = pos.y;

					if ((x >= tilePos.x  && x <= tilePos.x + 64) && (y >= tilePos.y && y <= tilePos.y + 64))
					{
						bullets.erase(bullets.begin() + i);
					}
				}
			}
				
		}
	}
}

int shotting::updateHowMuchAmmo(weapon weapon)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cooldown.getElapsedTime().asMilliseconds() > 150 && weapon.isLoaded == true)
	{
		return -1;
	}
}

shotting::shotting()
{

}
