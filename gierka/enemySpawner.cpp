#include "enemySpawner.h"
#include <random>
#include <iostream>


enemySpawner::enemySpawner()
{
	spawn1 = sf::Vector2f(318, 188);
	spawn2 = sf::Vector2f(316, 632);
	spawn3 = sf::Vector2f(516, 632);
	spawn4 = sf::Vector2f(512, 120);
	spawn5 = sf::Vector2f(704, 636);
	spawn6 = sf::Vector2f(1158, 124);
	spawn7 = sf::Vector2f(1536, 376);
	spawn8 = sf::Vector2f(1532, 194);
	spawn9 = sf::Vector2f(1280, 824);
	spawn10 = sf::Vector2f(1532, 1132);
	spawn11 = sf::Vector2f(1022, 1328);
}

void enemySpawner::enemySpawn(bool &waveBreak, int &firstWaveLag)
{
	

	if (enemies.size() == 0 && firstWaveLag != 0)
	{
		waveBreak = true;
		wave++;
		xDmg *= 0.9;
		howManySpawned = 0;
		//clock.restart();
	}
	
	if (clock.getElapsedTime().asMilliseconds() > 500 && howManySpawned != wave)
	{	
		std::cout << "asdad" << wave << std::endl;
		std::random_device random;
		std::mt19937 gen(random());
		std::uniform_int_distribution<> dis(1, 11);
		switch (dis(gen))
		{
		case 1:
			enemy1.enemySetPos(spawn1);
			break;
		case 2:
			enemy1.enemySetPos(spawn2);
			break;
		case 3:
			enemy1.enemySetPos(spawn3);
			break;
		case 4:
			enemy1.enemySetPos(spawn4);
			break;
		case 5:
			enemy1.enemySetPos(spawn5);
			break;
		case 6:
			enemy1.enemySetPos(spawn6);
			break;
		case 7:
			enemy1.enemySetPos(spawn7);
			break;
		case 8:
			enemy1.enemySetPos(spawn8);
			break;
		case 9:
			enemy1.enemySetPos(spawn9);
			break;
		case 10:
			enemy1.enemySetPos(spawn10);
			break;
		case 11:
			enemy1.enemySetPos(spawn11);
			break;
		}

		enemy1.setHpMaxBarPos();
		enemy1.setHpBarPos();

		enemies.push_back(enemy(enemy1));
			
		howManySpawned++;

		clock.restart();

		firstWaveLag++;
	}
}

void enemySpawner::enemyDraw(sf::RenderWindow &window)
{

	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i].setHpMaxBarPos();
		enemies[i].setHpBarPos();
		window.draw(enemies[i].enemyGetBody());
		window.draw(enemies[i].getHpMaxBar());
		window.draw(enemies[i].getHpBar());
	}
}

void enemySpawner::enemyCollision(shotting shotting, int damage)
{
	for (size_t j = 0; j < shotting.bullets.size(); j++)
	{
		for (size_t i = 0; i < enemies.size(); i++)
		{
			sf::FloatRect bulletsBounds = shotting.bullets[j].bulletObject.getGlobalBounds();
			sf::FloatRect enemyBounds = enemies[i].enemyBody.getGlobalBounds();
			if (bulletsBounds.intersects(enemyBounds))
			{				
				//shotting.bullets.erase(shotting.bullets.begin() + j);
				enemies[i].enemySetHp(shotting.bullets[j].damage, xDmg);
				
				//std::cout << damage << std::endl;
				if (enemies[i].HP <= 0)
				{
					std::random_device random;
					std::mt19937 gen(random());
					std::uniform_int_distribution<> dis(1, 3);
					money += dis(gen);
					enemies.erase(enemies.begin() + i);
				}
				
				//std::cout << "trafiony   " << shotting.bullets.size() <<"   "<<enemies[i].HP << std::endl;;
			}
		}
	}
	
	
	/*for (size_t i = 0; i < enemies.size(); i++)
	{
		for (size_t j = 0; j < shotting.bullets.size(); j++)
		{
			sf::FloatRect bulletsBounds = shotting.bullets[j].bulletObject.getGlobalBounds();
			sf::FloatRect enemyBounds = enemies[i].enemyBody.getGlobalBounds();
			if (enemyBounds.intersects(bulletsBounds))
			{
				shotting.bullets.erase(shotting.bullets.begin() + j);
				std::cout << "aa  \n";
			}
		}
	}*/
}