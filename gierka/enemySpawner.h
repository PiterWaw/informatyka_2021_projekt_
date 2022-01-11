#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include "mapa.h"
#include "shotting.h"
#include "weapon.h"

class enemySpawner
{
public:
	sf::Vector2f spawn1, spawn2, spawn3, spawn4, spawn5, spawn6, spawn7, spawn8, spawn9, spawn10, spawn11;
	int wave = 1;

	sf::Clock clock;

	enemy enemy1;
	std::vector<enemy> enemies;
	int howManySpawned = 0;
	
	enemySpawner();
	void enemySpawn();
	void enemyDraw(sf::RenderWindow& window);
	void enemyCollision(shotting shotting, int damage);
};
