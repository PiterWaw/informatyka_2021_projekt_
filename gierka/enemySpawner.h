#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "enemy.h"
#include "mapa.h"
#include "shotting.h"
#include "weapon.h"
#include <math.h>


class enemySpawner
{
public:
	sf::Vector2f spawn1, spawn2, spawn3, spawn4, spawn5, spawn6, spawn7, spawn8, spawn9, spawn10, spawn11;
	int wave = 10;
	int extraSpawn = 1;

	sf::Clock clock;
	
	sf::SoundBuffer hitb;
	sf::Sound hits;

	enemy enemy1;
	std::vector<enemy> enemies;
	int howManySpawned = 0;
	int money = 0;
	float xDmg = 1;

	enemySpawner();
	void enemySpawn(bool& waveBreak, int &firstWaveLag, player& player, bool& ammoReset);
	void enemyDraw(sf::RenderWindow& window);
	void enemyCollision(shotting &shotting, int damage, sf::Vector2f playerPos, mapa mapa, player &player);
	void enemyMovement(sf::Vector2f playerPos, mapa mapa);
};

