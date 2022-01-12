#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <vector>

class enemy
{
public:
	
	sf::Texture enemyTex;
	sf::RectangleShape hpMaxBar;
	sf::RectangleShape hpBar;
	float hpMax = 100;
	float HP = 100;
	sf::Sprite enemyBody;
	enemy();
	void enemySetPos(sf::Vector2f pos);
	sf::Sprite enemyGetBody();
	sf::Vector2f enemyGetPos();

	void setHpMaxBarPos();
	void setHpBarPos();
	sf::RectangleShape getHpMaxBar() { return hpMaxBar; }
	sf::RectangleShape getHpBar() { return hpBar; }

	void enemySetHp(float damage, float xDmg);
};

