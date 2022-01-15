#pragma once
#include <SFML/Graphics.hpp>
#include "waveBreak.h"



class gameOver : waveBreak
{
public:
	sf::Text lastInfoText;
	std::string lastInfoString;

	gameOver();
	void gameOverDisplay(sf::RenderWindow& window, int x, int y, sf::Event event, int waveNum, int& menuStage, bool& saveResaults);

};

