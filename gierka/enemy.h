#pragma once
#include <SFML/Graphics.hpp>
#include <random>

class enemy
{
private:
	sf::Sprite *enemyBody;
	sf::Texture enemyTex;
	sf::Vector2f spawn1, spawn2, spawn3, spawn4, spawn5;
	int areSpawned = 0;
public:
	enemy();
	void enemyLoad();
	void spawnEnemy(int N);
	void enemyDraw(sf::RenderWindow &window, int N);
};

