#pragma once
#include <SFML/Graphics.hpp>
#include "waveBreak.h"
#include <iostream>
#include <sstream>

#pragma warning(disable : 4996)

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class menu : waveBreak
{
public:
	sf::Sprite button4;
	sf::Text leaderboard;

	sf::Text nick;
	std::ostringstream nickStream;
	bool isSelected = true;

	std::string gracz1;
	

	menu();
	void inputLogic(int charTyped);
	void deleteLastChar();
	std::string getText();
	void drawTo(sf::RenderWindow& window);
	void setSelected(bool sel);
	void typedOn(sf::Event event);
	void menuDisplay(sf::RenderWindow& window, sf::Event event, int& menuStage, sf::View &view, bool& waveBreak);

	
};

