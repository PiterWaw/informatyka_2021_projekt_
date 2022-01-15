#pragma once
#include <SFML/Graphics.hpp>
#include "waveBreak.h"

class menu : waveBreak
{
public:
	sf::Sprite button4;
	sf::Text leaderboard;

	menu();
	void menuDisplay(sf::RenderWindow& window, sf::Event event, int& menuStage, sf::View &view, bool& waveBreak);
};

