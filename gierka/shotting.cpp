#include "shotting.h"


void shotting::shottingUpdate(sf::RenderWindow& window, sf::Vector2f mousePos, sf::Vector2f weaponPos, mapa mapa, weapon& weapon, int whichWeapon)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (cooldown.getElapsedTime().asMilliseconds() > weapon.fireRate || isFirstShot == true) && weapon.isLoaded == true)
	{	
		isFirstShot = false;
		b1.aimDir = mousePos - weaponPos;
		b1.aimDirNorm = sf::Vector2f(b1.aimDir.x / sqrt(pow(b1.aimDir.x, 2) + pow(b1.aimDir.y, 2)), b1.aimDir.y / sqrt(pow(b1.aimDir.x, 2) + pow(b1.aimDir.y, 2)));

		b1.bulletObject.setPosition(sf::Vector2f(weaponPos.x ,weaponPos.y));

		b1.currentVelocity = b1.aimDirNorm * b1.bulletSpeed;

		b1.damage = weapon.damage;
		bullets.push_back(bullet(b1));
		if (whichWeapon == 1) sound3.play();
		if (whichWeapon == 2) sound2.play();
		if (whichWeapon == 3) sound1.play();

		weapon.ammo--;
		cooldown.restart();

		

		if (weapon.ammo <= 0)
		{
			weapon.isLoaded = false;
			weapon.reloadColdown.restart();
			if (whichWeapon == 1) r.play();
			if (whichWeapon == 2) s.play();
			if (whichWeapon == 3) m.play();
		}
	}
	else if ((weapon.isLoaded == false && weapon.reloadColdown.getElapsedTime().asMilliseconds() > 2000) )
	{
		weapon.isLoaded = true;
		weapon.ammo = weapon.maxAmmo;
		//std::cout << "roz\n";
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
	if (!buffer1.loadFromFile("Sounds/1.wav")) std::cout << "ERROR" << std::endl;
	if (!buffer2.loadFromFile("Sounds/2.wav")) std::cout << "ERROR" << std::endl;
	if (!buffer3.loadFromFile("Sounds/3.wav")) std::cout << "ERROR" << std::endl;
	if (!sb.loadFromFile("Sounds/s.wav")) std::cout << "ERROR" << std::endl;
	if (!rb.loadFromFile("Sounds/r.wav")) std::cout << "ERROR" << std::endl;
	if (!mb.loadFromFile("Sounds/m.wav")) std::cout << "ERROR" << std::endl;



	sound1.setBuffer(buffer1);
	sound2.setBuffer(buffer2);
	sound3.setBuffer(buffer3);
	sound3.setVolume(20);
	r.setBuffer(rb);
	s.setBuffer(sb);
	m.setBuffer(mb);
}
