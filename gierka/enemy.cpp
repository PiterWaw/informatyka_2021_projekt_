#include "enemy.h"
#include <iostream>

enemy::enemy()
{
	enemyTex.loadFromFile("Textures/enemy.png");
	spawn1 = sf::Vector2f(70, 70);
	spawn2 = sf::Vector2f(200, 200);
	spawn3 = sf::Vector2f(1500, 700);
	spawn4 = sf::Vector2f(600, 200);
	spawn5 = sf::Vector2f(70, 600);
	enemyBody = new sf::Sprite[5];
	for (int i = 0; i < 5; i++)
	{
		//if (clock.getElapsedTime().asMilliseconds() > 500.0f) {
		enemyBody[i].setTexture(enemyTex);
		std::random_device random;
		std::mt19937 gen(random());
		std::uniform_int_distribution<> dis(1, 5);
		std::cout << dis(gen) << std::endl;
		if (dis(gen) == 1) enemyBody->setPosition(spawn1);
		if (dis(gen) == 2) enemyBody->setPosition(spawn2);
		if (dis(gen) == 3) enemyBody->setPosition(spawn3);
		if (dis(gen) == 4) enemyBody->setPosition(spawn4);
		if (dis(gen) == 5) enemyBody->setPosition(spawn5);
		//clock.restart();
		//if (i == N) areSpawned = 1;
		//}
	}
}
void enemy::enemyLoad()
{	
	spawn1 = sf::Vector2f(70, 70);
	spawn2 = sf::Vector2f(200, 200);
	spawn3 = sf::Vector2f(1500, 700);
	spawn4 = sf::Vector2f(600, 200);
	spawn5 = sf::Vector2f(70, 600);
}
void enemy::spawnEnemy(int N)
{
	sf::Clock clock;
	//while (areSpawned == 0)
	//{
		enemyBody = new sf::Sprite[N];
		for (int i = 0; i < N; i++)
		{
			//if (clock.getElapsedTime().asMilliseconds() > 500.0f) {
				enemyBody[i].setTexture(enemyTex);
				std::random_device random;
				std::mt19937 gen(random());
				std::uniform_int_distribution<> dis(1, 5);
				if (dis(gen) == 1) enemyBody->setPosition(spawn1);
				if (dis(gen) == 2) enemyBody->setPosition(spawn2);
				if (dis(gen) == 3) enemyBody->setPosition(spawn3);
				if (dis(gen) == 4) enemyBody->setPosition(spawn4);
				if (dis(gen) == 5) enemyBody->setPosition(spawn5);
				clock.restart();
				if (i == N) areSpawned = 1;
			//}
		//}
	}
}
void enemy::enemyDraw(sf::RenderWindow &window, int N)
{
	//while (areSpawned == 1)
	//{
		for (int i = 1; i < N; i++)
		{
			window.draw(enemyBody[i]);
		}
	//}
}