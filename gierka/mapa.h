#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"
#include <vector>

class mapa
{
public:
	sf::RectangleShape tileWall;
	std::vector<sf::RectangleShape> tilesArr;
	int sizeX = 26, sizeY = 26;
	int px = 64;
	int mapaa[26][26] = { 					  
					  { 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6 },
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2 },
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2 },
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2 },
					  { 2, 9, 9, 9, 8, 9, 9, 9, 9, 9, 9, 2 },
					  { 2, 9, 9, 9, 2, 9, 9, 9, 9, 9, 9, 2 },
					  { 7, 1, 1, 1, 5, 9, 9, 9, 9, 9, 9, 2, 1, 1, 1, 1, 1, 2},
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2},
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2},
					  { 2, 9, 9, 9, 9, 9, 1, 1, 1, 1, 1, 2, 1, 1, 1, 9, 9, 2, 2},
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2, 0, 0, 2, 9, 9, 9, 2},
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2, 0, 0, 2, 9, 9, 9, 2},
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2, 0, 0, 2, 2, 9, 9, 2},
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2, 0, 0, 0 ,2, 9, 9, 2},
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2, 0, 0, 0, 2, 9, 9, 1, 1, 1, 1, 1},
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2, 0, 0, 0, 2, 9, 9, 9, 9, 9, 9, 1},
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2, 0, 0, 0, 2, 1, 9, 9, 9, 9, 9, 1},
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2, 0, 0, 0, 0, 1, 9, 9, 1, 1, 1, 1},
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2, 1, 1, 1, 1, 1, 9, 9, 6 },
					  { 7, 1, 1, 1, 1, 1, 1, 1, 9, 9, 1, 2, 9, 9, 9, 9, 9, 9, 9, 2 },
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2, 9, 9, 9, 9, 9, 9, 9, 2 },
					  { 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2, 9, 9, 9, 9, 9, 9, 9, 2 },
					  { 2, 9, 9, 1, 6, 9, 9, 9, 9, 9, 9, 2, 9, 9, 9, 9, 9, 9, 9, 2 },
					  { 2, 9, 9, 9, 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2 },
					  { 2, 9, 9, 9, 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2 },
					  { 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5 } };
	sf::Texture podlogaF, scianaR, scianaR1, scianaR2, scianaR3, scianaR4, scianaR5, scianaR6, scianaR7, scianaR8, puste;
	std::string podlogaFF = "Textures/podlogaF.png";
	std::string pustee = "Textures/puste.png";
	std::string scianaRR = "Textures/scianaR.png";
	std::string scianaRR1 = "Textures/scianaR1.png";
	std::string scianaRR2 = "Textures/scianaR2.png";
	std::string scianaRR3 = "Textures/scianaR3.png";
	std::string scianaRR4 = "Textures/scianaR4.png";
	std::string scianaRR5 = "Textures/scianaR5.png";
	std::string scianaRR6 = "Textures/scianaR6.png";
	std::string scianaRR7 = "Textures/scianaR7.png";
	std::string scianaRR8 = "Textures/scianaR8.png";
	sf::Sprite tile;
	sf::Sprite loadTile( int x, int y);
	void loadFiles();
	int collisionLeft(player player1);
	int collisionRight(player player1);
	int collisionUp(player player1);
	int collisionDown(player player1);
	int getSizeX() { return sizeX; };
	int getSizeY() { return sizeY; };
	mapa();

};
