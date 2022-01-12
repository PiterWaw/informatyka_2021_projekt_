#include <SFML/Graphics.hpp>
#include <iostream>
#include "mapa.h"
#include "weapon.h"
#include "enemy.h"
#include "bullet.h"
#include <vector>
#include <math.h>
#include "shotting.h"
#include "enemySpawner.h"
#include "HUD.h"
#include "waveBreak.h"

int main()
{
	sf::RenderWindow gra(sf::VideoMode(1920, 1080), "Gierka Alpha v0.1", sf::Style::Fullscreen); //1280, 768
	
	sf::Clock lag;

	player player1;
	float speed;
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(1920, 1080));
	view.setCenter(sf::Vector2f(player1.getPlayerPosition().x + 32, player1.getPlayerPosition().y + 32));
	sf::Vector2f mouse_pos;
	int movementSpeedLeft = player1.getSpeed();
	int movementSpeedRight = player1.getSpeed();
	int movementSpeedUp = player1.getSpeed();
	int movementSpeedDown = player1.getSpeed();

	gra.setFramerateLimit(60);
	mapa mapa1;
	weapon m4a4;
	weapon shotgun;
	weapon minigun;
	shotting shotting;
	enemySpawner enemySpawner;
	HUD HUD;
	waveBreak waveBreak;
	mapa1.loadFiles();
	int whichWeapon = 1;

	m4a4.maxAmmo = 30;
	m4a4.ammo = 30;
	m4a4.damage = 3;
	m4a4.fireRate = 150;
	m4a4.isUnlocked = true;

	shotgun.maxAmmo = 5;
	shotgun.ammo = 5;
	shotgun.damage = 10;
	shotgun.fireRate = 1500;

	minigun.maxAmmo = 100;
	minigun.ammo = 100;
	minigun.damage = 1;
	minigun.fireRate = 60;
	//minigun.isUnlocked = true;


	int HUDx = player1.getPlayerPosition().x;
	int HUDy = player1.getPlayerPosition().y;
	int sizeX = mapa1.getSizeX();
	int sizeY = mapa1.getSizeY();
	int firstWaveLag = 0;

	bool waveBreaks = true;

	while (gra.isOpen())
	{
		sf::Event event;
		while (gra.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				gra.close();
				break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
		{
			gra.close();
		}

		gra.setView(view);
		HUDx = player1.getPlayerPosition().x;
		HUDy = player1.getPlayerPosition().y;

		

		if (waveBreaks == true || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			waveBreaks = true;
			gra.clear(sf::Color(241, 221, 221));
			
			for (int i = 0; i < sizeX; i++)
			{
				for (int j = 0; j < sizeY; j++)
				{
					gra.draw(mapa1.loadTile(i, j));
				}
			}
			HUD.hudDisplay(gra, HUDx, HUDy, shotgun, shotgun.isLoaded, player1.hp, player1.hpMax, whichWeapon, enemySpawner.enemies.size(), enemySpawner.wave, shotgun.isUnlocked, minigun.isUnlocked);
			
			waveBreak.waveBreakDisplay(gra, HUDx, HUDy, m4a4, shotgun, minigun, enemySpawner.money, shotgun.isUnlocked, minigun.isUnlocked, waveBreaks, event);

		}
		else
		{
			speed = player1.getSpeed();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player1.movePlayer(-movementSpeedLeft, 0.f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player1.movePlayer(0.f, movementSpeedDown);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player1.movePlayer(movementSpeedRight, 0.f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player1.movePlayer(0.f, -movementSpeedUp);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && m4a4.isUnlocked == true)
			{
				if (whichWeapon != 1)
				{
					shotting.isFirstShot = true;
					m4a4.reloadColdown.restart();
				}
				whichWeapon = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && shotgun.isUnlocked == true)
			{
				if (whichWeapon != 2)
				{
					shotting.isFirstShot = true;
					shotgun.reloadColdown.restart();
				}
				whichWeapon = 2;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && minigun.isUnlocked == true)
			{
				if (whichWeapon != 3)
				{
					shotting.isFirstShot = true;
					minigun.reloadColdown.restart();
				}
				whichWeapon = 3;
			}

			gra.clear(sf::Color(241, 221, 221));

			
			for (int i = 0; i < sizeX; i++)
			{
				for (int j = 0; j < sizeY; j++)
				{
					gra.draw(mapa1.loadTile(i, j));
				}
			}

			movementSpeedLeft = mapa1.collisionLeft(player1);
			movementSpeedRight = mapa1.collisionRight(player1);
			movementSpeedUp = mapa1.collisionUp(player1);
			movementSpeedDown = mapa1.collisionDown(player1);

			gra.draw(player1.getPlayer());

			mouse_pos = gra.mapPixelToCoords(sf::Mouse::getPosition(gra));


			


			if (whichWeapon == 1)
			{
				m4a4.changeWeapon(whichWeapon);

				m4a4.updatePos(sf::Vector2f(player1.getPlayerPosition()), mouse_pos);
				gra.draw(m4a4.getWeapon());

				view.setCenter(sf::Vector2f(player1.getPlayerPosition().x + 32, player1.getPlayerPosition().y + 32));

				enemySpawner.enemyCollision(shotting, shotting.b1.damage);
				enemySpawner.enemySpawn(waveBreaks, firstWaveLag);
				enemySpawner.enemyDraw(gra);

				shotting.bulletCollision(mapa1);
				shotting.shottingUpdate(gra, mouse_pos, m4a4.weaponBody.getPosition(), mapa1, m4a4);

				HUD.hudDisplay(gra, HUDx, HUDy, m4a4, m4a4.isLoaded, player1.hp, player1.hpMax, whichWeapon, enemySpawner.enemies.size(), enemySpawner.wave, shotgun.isUnlocked, minigun.isUnlocked);
			}
			else if (whichWeapon == 2)
			{
				shotgun.changeWeapon(whichWeapon);

				shotgun.updatePos(sf::Vector2f(player1.getPlayerPosition()), mouse_pos);
				gra.draw(shotgun.getWeapon());

				view.setCenter(sf::Vector2f(player1.getPlayerPosition().x + 32, player1.getPlayerPosition().y + 32));

				enemySpawner.enemyCollision(shotting, shotgun.damage);
				enemySpawner.enemySpawn(waveBreaks, firstWaveLag);
				enemySpawner.enemyDraw(gra);

				shotting.bulletCollision(mapa1);
				shotting.shottingUpdate(gra, mouse_pos, shotgun.weaponBody.getPosition(), mapa1, shotgun);

				HUD.hudDisplay(gra, HUDx, HUDy, shotgun, shotgun.isLoaded, player1.hp, player1.hpMax, whichWeapon, enemySpawner.enemies.size(), enemySpawner.wave, shotgun.isUnlocked, minigun.isUnlocked);
			}
			else if (whichWeapon == 3)
			{
				minigun.changeWeapon(whichWeapon);

				minigun.updatePos(sf::Vector2f(player1.getPlayerPosition()), mouse_pos);
				gra.draw(minigun.getWeapon());

				view.setCenter(sf::Vector2f(player1.getPlayerPosition().x + 32, player1.getPlayerPosition().y + 32));

				enemySpawner.enemyCollision(shotting, minigun.damage);
				enemySpawner.enemySpawn(waveBreaks, firstWaveLag);
				enemySpawner.enemyDraw(gra);

				shotting.bulletCollision(mapa1);
				shotting.shottingUpdate(gra, mouse_pos, minigun.weaponBody.getPosition(), mapa1, minigun);

				HUD.hudDisplay(gra, HUDx, HUDy, minigun, minigun.isLoaded, player1.hp, player1.hpMax, whichWeapon, enemySpawner.enemies.size(), enemySpawner.wave, shotgun.isUnlocked, minigun.isUnlocked);
			}

			//waveBreak = enemySpawner.isWaveEnded;
			

			//std::cout << m4a4.damage << " " << shotgun.damage << " " << minigun.damage << std::endl;



			/*std::cout <<"m4a4: "<< m4a4.ammo << "   " << m4a4.maxAmmo << std::endl;
			std::cout << "shotgun: " << shotgun.ammo << "   " << shotgun.maxAmmo << std::endl;
			std::cout << "minigun: " << minigun.ammo << "   " << minigun.maxAmmo << std::endl;*/




			//std::cout << player1.getPlayerPosition().x <<"   "<<player1.getPlayerPosition().y << std::endl;
		}

		
		
		
		
		gra.display();
	}
}