#include <SFML/Graphics.hpp>
#include <iostream>
#include "mapa.h"
#include "weapon.h"
#include "enemy.h"

int main()
{
	sf::RenderWindow gra(sf::VideoMode(1280, 768), "Gierka Alpha v0.1");
	player player1;
	float speed;
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(1280, 768));
	view.setCenter(sf::Vector2f(player1.getPlayerPosition().x + 32, player1.getPlayerPosition().y + 32));
	sf::Vector2f mouse_pos;
	int movementSpeedLeft = player1.getSpeed();
	int movementSpeedRight = player1.getSpeed();
	int movementSpeedUp = player1.getSpeed();
	int movementSpeedDown = player1.getSpeed();

	gra.setFramerateLimit(60);
	mapa mapa1;
	weapon weapon1;
	enemy enemy;
	//enemy.enemyLoad();
	mapa1.loadFiles();

	int sizeX = mapa1.getSizeX();
	int sizeY = mapa1.getSizeY();

	while (gra.isOpen())
	{
		sf::Event event;
		while (gra.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gra.close();
		}

		

		speed = player1.getSpeed();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player1.movePlayer(-movementSpeedLeft, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player1.movePlayer(0.f, movementSpeedDown);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player1.movePlayer(movementSpeedRight, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player1.movePlayer(0.f, -movementSpeedUp);
		gra.clear(sf::Color::White);

		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				gra.draw(mapa1.loadTile(i, j));
			}
		}

		//enemy.spawnEnemy(5);
		enemy.enemyDraw(gra, 5);

		movementSpeedLeft = mapa1.collisionLeft(player1);
		movementSpeedRight = mapa1.collisionRight(player1);
		movementSpeedUp = mapa1.collisionUp(player1);
		movementSpeedDown = mapa1.collisionDown(player1);

		gra.draw(player1.getPlayer());
		
		mouse_pos = gra.mapPixelToCoords(sf::Mouse::getPosition(gra));
		weapon1.updatePos(sf::Vector2f(player1.getPlayerPosition()), mouse_pos);

		gra.draw(weapon1.getWeapon());
		view.setCenter(sf::Vector2f(player1.getPlayerPosition().x + 32, player1.getPlayerPosition().y + 32));
		

		gra.setView(view);
		gra.display();
	}
}