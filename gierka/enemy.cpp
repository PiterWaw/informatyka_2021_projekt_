#include "enemy.h"
#include <iostream>

enemy::enemy()
{
	enemyTex.loadFromFile("Textures/enemy.png");
	enemyBody.setTexture(enemyTex);
	enemyBody.setOrigin(32, 32);
	hpMaxBar.setSize(sf::Vector2f(hpMax, 5));
	hpMaxBar.setFillColor(sf::Color::Red);
	hpBar.setSize(sf::Vector2f(HP, 5));
	hpBar.setFillColor(sf::Color::Green);
}

void enemy::enemySetPos(sf::Vector2f pos)
{
	enemyBody.setPosition(pos);
}

sf::Sprite enemy::enemyGetBody()
{
	return enemyBody;
}

sf::Vector2f enemy::enemyGetPos()
{
	return enemyBody.getPosition();
}

void enemy::setHpMaxBarPos()
{
	hpMaxBar.setPosition(sf::Vector2f(enemyBody.getPosition().x - 50, enemyBody.getPosition().y - 60));
}

void enemy::setHpBarPos()
{
	hpBar.setPosition(hpMaxBar.getPosition());
	hpBar.setSize(sf::Vector2f(HP, 5));
}

void enemy::enemySetHp(int damage)
{
	HP -= damage;
}