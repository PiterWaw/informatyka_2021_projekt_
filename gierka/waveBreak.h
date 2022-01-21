#pragma once
#include <SFML/Graphics.hpp>
#include "weapon.h"
#include <iostream>

class waveBreak
{
public:
	sf::Sprite button1;
	sf::Sprite button5;
	sf::Sprite button2;
	sf::Sprite button3;
	sf::Texture buttonTex;
	
	sf::Sprite infoWaveBox;
	sf::Texture infoWaveBoxTex;

	sf::Sprite infoWaveBoxEmpty;
	sf::Texture infoWaveBoxTexEmpty;

	sf::RectangleShape button1Hover;

	sf::Sprite upgrade1;
	sf::Sprite upgrade2;
	sf::Sprite upgrade3;
	sf::Texture upgradeTex;

	sf::RectangleShape button2Hover;

	sf::Text money;
	sf::Font font;
	std::string moneyString;

	sf::Text upgradeText1;
	std::string upgradeTextString1;
	sf::Text upgradeText2;
	std::string upgradeTextString2;
	sf::Text upgradeText3;
	std::string upgradeTextString3;

	sf::Text buy1;
	sf::Text buy2;

	sf::Text resume;
	sf::Text help;
	sf::Text exit;
	sf::Text helpInfo;

	sf::Clock lag;

	sf::Text lvl1;
	sf::Text lvl2;
	sf::Text lvl3;
	sf::Text lvlInfo;

	sf::Clock delay;

	

	waveBreak();
	void waveBreakDisplay(sf::RenderWindow& window, int x, int y, weapon& m4a4, weapon& shotgun, weapon& minigun, int& moneyy, bool shotgunIsUnlocked, bool minigunIsUnlocked, bool &waveBreakk, sf::Event event, bool& firstWaveLag, int& menuStage);
	bool isMouseOver(sf::RenderWindow& window, sf::Sprite button, int x, int y);
	bool isButtonPushed(sf::RenderWindow& window, sf::Sprite button, int x, int y, sf::Event event);
};

