#include "mapa.h"
#include <iostream>


sf::Sprite mapa::loadTile(int x, int y)
{
	switch (mapaa[x][y])
	{
	case 9:
		tile.setTexture(podlogaF);
		break;
	case 0:
		tile.setTexture(puste);
		break;
	case 1:
		tile.setTexture(scianaR1);
		break;
	case 2:
		tile.setTexture(scianaR2);
		break;
	case 3:
		tile.setTexture(scianaR3);
		break;
	case 4:
		tile.setTexture(scianaR4);
		break;
	case 5:
		tile.setTexture(scianaR5);
		break;
	case 6:
		tile.setTexture(scianaR6);
		break;
	case 7:
		tile.setTexture(scianaR7);
		break;
	case 8:
		tile.setTexture(scianaR8);
		break;
	}

	tile.setPosition(x * 64, y * 64);
	//std::cout << x << " " << y << std::endl;
	return tile;
}
void mapa::loadFiles()
{
	puste.loadFromFile("Textures/puste.png");
	podlogaF.loadFromFile("Textures/podlogaF.png");
	scianaR.loadFromFile("Textures/scianaR.png");
	scianaR1.loadFromFile("Textures/scianaR1.png");
	scianaR2.loadFromFile("Textures/scianaR2.png");
	scianaR3.loadFromFile("Textures/scianaR3.png");
	scianaR4.loadFromFile("Textures/scianaR4.png");
	scianaR5.loadFromFile("Textures/scianaR5.png");
	scianaR6.loadFromFile("Textures/scianaR6.png");
	scianaR7.loadFromFile("Textures/scianaR7.png");
	scianaR8.loadFromFile("Textures/scianaR8.png");
}
mapa::mapa()
{

}
int mapa::collisionLeft(player player1)
{
	sf::Vector2f pos = player1.getPlayerPosition();
	int x = pos.x;
	int y = pos.y;
	int movementSpeedLeft = player1.getSpeed();

	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			if (mapaa[i][j] != 9)
			{
				sf::Vector2f tilePos;
				tilePos.x = i * 64;
				tilePos.y = j * 64;
				if (x - tilePos.x + 2 > 0 && x < tilePos.x + px + 2 && y + px > tilePos.y && y < tilePos.y + px) return movementSpeedLeft = 0;
			}
		}
	}
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			if (mapaa[i][j] != 9)
			{
				sf::Vector2f tilePos;
				tilePos.x = i * 64;
				tilePos.y = j * 64;
				if (x - tilePos.x > 0 && x < tilePos.x + px && y + px > tilePos.y && y < tilePos.y + px) return movementSpeedLeft = 0;
				else return movementSpeedLeft = player1.getSpeed();
			}
		}
	}
}
int mapa::collisionRight(player player1)
{
	sf::Vector2f pos = player1.getPlayerPosition();
	int x = pos.x;
	int y = pos.y;
	int movementSpeedRight = player1.getSpeed();

	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			if (mapaa[i][j] != 9)
			{
				sf::Vector2f tilePos;
				tilePos.x = i * 64;
				tilePos.y = j * 64;
				if (x - tilePos.x + px + 2 > 0 && x < tilePos.x + 2 && y + px > tilePos.y && y < tilePos.y + px) return movementSpeedRight = 0;
			}
		}
	}
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			if (mapaa[i][j] != 9)
			{
				sf::Vector2f tilePos;
				tilePos.x = i * 64;
				tilePos.y = j * 64;
				if (x - tilePos.x + px > 0 && x < tilePos.x && y + px > tilePos.y && y < tilePos.y + px) return movementSpeedRight = 0;
				else return movementSpeedRight = player1.getSpeed();
			}
		}
	}
}
int mapa::collisionUp(player player1)
{
	sf::Vector2f pos = player1.getPlayerPosition();
	int x = pos.x;
	int y = pos.y;
	int movementSpeedUp = player1.getSpeed();

	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			if (mapaa[i][j] != 9)
			{
				sf::Vector2f tilePos;
				tilePos.x = i * 64;
				tilePos.y = j * 64;
				if (y - tilePos.y + 2 > 0 && y < tilePos.y + 2 + px && x + px > tilePos.x && x < tilePos.x + px) return movementSpeedUp = 0;
			}
		}
	}
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			if (mapaa[i][j] != 9)
			{
				sf::Vector2f tilePos;
				tilePos.x = i * 64;
				tilePos.y = j * 64;
				if (y - tilePos.y > 0 && y < tilePos.y + px && x + px > tilePos.x && x < tilePos.x + px) return movementSpeedUp = 0;
				else return movementSpeedUp = player1.getSpeed();
			}
		}
	}
}
int mapa::collisionDown(player player1)
{
	sf::Vector2f pos = player1.getPlayerPosition();
	int x = pos.x;
	int y = pos.y;
	int movementSpeedDown = player1.getSpeed();

	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			if (mapaa[i][j] != 9)
			{
				sf::Vector2f tilePos;
				tilePos.x = i * 64;
				tilePos.y = j * 64;
				if (y - tilePos.y + px + 2 > 0 && y < tilePos.y + 2 && x + px > tilePos.x && x < tilePos.x + px) return movementSpeedDown = 0;
			}
		}
	}
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			if (mapaa[i][j] != 9)
			{
				sf::Vector2f tilePos;
				tilePos.x = i * 64;
				tilePos.y = j * 64;
				if (y - tilePos.y + px > 0 && y < tilePos.y && x + px > tilePos.x && x < tilePos.x + px) return movementSpeedDown = 0;
				else return movementSpeedDown = player1.getSpeed();
			}
		}
	}
}
