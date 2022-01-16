#include "waveBreak.h"


waveBreak::waveBreak()
{
	buttonTex.loadFromFile("Textures/button.png");
	button1.setTexture(buttonTex);
	button2.setTexture(buttonTex);
	button3.setTexture(buttonTex);
	

	button1.setOrigin(96, 32);
	button2.setOrigin(96, 32);
	button3.setOrigin(96, 32);
	
	button1Hover.setOrigin(96, 32);
	button1Hover.setSize(sf::Vector2f(192,64));
	
	infoWaveBoxTex.loadFromFile("Textures/infoWaveBox.png");
	infoWaveBox.setTexture(infoWaveBoxTex);
	infoWaveBox.setOrigin(200, 150);

	infoWaveBoxTexEmpty.loadFromFile("Textures/infoBox.png");
	infoWaveBoxEmpty.setTexture(infoWaveBoxTexEmpty);
	infoWaveBoxEmpty.setOrigin(200, 150);

	upgradeTex.loadFromFile("Textures/smallButton.png");
	upgrade1.setTexture(upgradeTex);
	upgrade2.setTexture(upgradeTex);
	upgrade3.setTexture(upgradeTex);

	upgrade1.setOrigin(96, 21.5);
	upgrade2.setOrigin(96, 21.5);
	upgrade3.setOrigin(96, 21.5);
	button2Hover.setOrigin(96, 21.5);
	button2Hover.setSize(sf::Vector2f(192, 43));

	font.loadFromFile("font.ttf");
	money.setFont(font);
	money.setFillColor(sf::Color::Black);

	upgradeText1.setFont(font);
	upgradeText2.setFont(font);
	upgradeText3.setFont(font);
	buy1.setFont(font);
	buy2.setFont(font);
	upgradeText1.setFillColor(sf::Color::Black);
	upgradeText2.setFillColor(sf::Color::Black);
	upgradeText3.setFillColor(sf::Color::Black);
	buy1.setFillColor(sf::Color::Black);
	buy2.setFillColor(sf::Color::Black);

	upgradeText1.setString("Upgrade Cost: 100");
	upgradeText2.setString("Upgrade Cost: 100");
	upgradeText3.setString("Upgrade Cost: 100");
	buy1.setString("Cost to Buy: 150");
	buy2.setString("Cost to Buy: 150");
	upgradeText1.setCharacterSize(20);
	upgradeText2.setCharacterSize(20);
	upgradeText3.setCharacterSize(20);
	buy1.setCharacterSize(20);
	buy2.setCharacterSize(20);

	resume.setFont(font);
	resume.setFillColor(sf::Color::Black);
	help.setFont(font);
	help.setFillColor(sf::Color::Black);
	exit.setFont(font);
	exit.setFillColor(sf::Color::Black);
	helpInfo.setFont(font);
	helpInfo.setFillColor(sf::Color::Black);
	helpInfo.setCharacterSize(25);

	lvl1.setFont(font);
	lvl1.setFillColor(sf::Color::Black);
	lvl2.setFont(font);
	lvl2.setFillColor(sf::Color::Black);
	lvl3.setFont(font);
	lvl3.setFillColor(sf::Color::Black);
	lvl1.setCharacterSize(20);
	lvl2.setCharacterSize(20);
	lvl3.setCharacterSize(20);
	lvlInfo.setFont(font);
	lvlInfo.setFillColor(sf::Color::Black);
	lvlInfo.setCharacterSize(15);
}

void waveBreak::waveBreakDisplay(sf::RenderWindow& window, int x, int y, weapon &m4a4, weapon& shotgun, weapon& minigun, int &moneyy, bool shotgunIsUnlocked, bool minigunIsUnlocked, bool &waveBreakk, sf::Event event, bool& firstWaveLag, int &menuStage)
{
	
	if (firstWaveLag == true)
	{
		m4a4.ammo = m4a4.maxAmmo;
		shotgun.ammo = shotgun.maxAmmo;
		minigun.ammo = minigun.maxAmmo;
		m4a4.isLoaded = true;
		shotgun.isLoaded = true;
		minigun.isLoaded = true;
	}

	button1Hover.setFillColor(sf::Color(134, 134, 134, 80));
	button2Hover.setFillColor(sf::Color(134, 134, 134, 80));

	button1.setPosition(x - 170, y - 117);
	button2.setPosition(x - 170, y);
	button3.setPosition(x - 170, y + 117);
	window.draw(button1);
	window.draw(button2);
	window.draw(button3);

	infoWaveBox.setPosition(x + 150, y);
	infoWaveBoxEmpty.setPosition(x + 150, y);
	window.draw(infoWaveBox);

	upgrade1.setPosition(x + 170, y - 35);
	upgrade2.setPosition(x + 170, y + 25);
	upgrade3.setPosition(x + 170, y + 85);
	window.draw(upgrade1);
	window.draw(upgrade2);
	window.draw(upgrade3);

	moneyString = "Your money: " + std::to_string(moneyy);
	money.setString(moneyString);
	money.setPosition(x + 60, y - 120);
	window.draw(money);

	upgradeText1.setPosition(x + 90, y - 47);
	upgradeText2.setPosition(x + 90, y + 13);
	upgradeText3.setPosition(x + 90, y + 73);
	buy1.setPosition(x + 90, y + 13);
	buy2.setPosition(x + 90, y + 73);
	window.draw(upgradeText1);
	if (shotgunIsUnlocked == true) window.draw(upgradeText2);
	else window.draw(buy1);
	if (minigunIsUnlocked == true) window.draw(upgradeText3);
	else window.draw(buy2);

	resume.setString("RESUME");
	help.setString("HELP");
	exit.setString("EXIT");
	resume.setPosition(x - 225, y - 135);
	help.setPosition(x - 205, y - 18);
	exit.setPosition(x - 200, y + 99);
	window.draw(resume);
	window.draw(help);
	window.draw(exit);

	lvlInfo.setString("Level");
	lvl1.setString(std::to_string(m4a4.lvl));
	lvl2.setString(std::to_string(shotgun.lvl));
	lvl3.setString(std::to_string(minigun.lvl));
	lvlInfo.setPosition(x - 30, y - 80);
	lvl1.setPosition(x - 20, y - 47);
	lvl2.setPosition(x - 20, y + 13);
	lvl3.setPosition(x - 20, y + 73);
	window.draw(lvl1);
	window.draw(lvl2);
	window.draw(lvl3);
	window.draw(lvlInfo);


	helpInfo.setString("Move with: WSAD\n\nEarn money by killing\nthe enemies!\n\nChange weapon with buttons: 1, 2, 3");
	helpInfo.setPosition(x-32, y-100);
	
	if (isMouseOver(window, button1, x, y) == true)
	{
		button1Hover.setPosition(button1.getPosition().x, button1.getPosition().y);	
		window.draw(button1Hover);
	}
	else if (isMouseOver(window, button2, x, y) == true)
	{
		button1Hover.setPosition(button2.getPosition().x, button2.getPosition().y);
		window.draw(button1Hover);
	}
	else if (isMouseOver(window, button3, x, y) == true)
	{
		button1Hover.setPosition(button3.getPosition().x, button3.getPosition().y);
		window.draw(button1Hover);
	}
	else if (isMouseOver(window, upgrade1, x, y) == true)
	{
		button2Hover.setPosition(upgrade1.getPosition().x, upgrade1.getPosition().y);
		window.draw(button2Hover);
	}
	else if (isMouseOver(window, upgrade2, x, y) == true)
	{
		button2Hover.setPosition(upgrade2.getPosition().x, upgrade2.getPosition().y);
		window.draw(button2Hover);
	}
	else if (isMouseOver(window, upgrade3, x, y) == true)
	{
		button2Hover.setPosition(upgrade3.getPosition().x, upgrade3.getPosition().y);
		window.draw(button2Hover);
	}

	/// /// /// ///

	if (isButtonPushed(window, button1, x, y, event) == true)
	{
		waveBreakk = false;
	}
	else if (isButtonPushed(window, button2, x, y, event) == true)
	{
		window.draw(infoWaveBoxEmpty);
		window.draw(helpInfo);
	}
	else if (isButtonPushed(window, button3, x, y, event) == true)
	{
		menuStage = 1;
		waveBreakk = false;
	}
	else if (isButtonPushed(window, upgrade1, x, y, event) == true)
	{
		if (moneyy >= 100)
		{
			m4a4.damage+=15;
			moneyy -= 100;
			m4a4.lvl++;
		}
	}
	else if (isButtonPushed(window, upgrade2, x, y, event) == true && shotgunIsUnlocked == true)
	{
		if (moneyy >= 100)
		{
			shotgun.damage += 30;
			moneyy -= 100;
			shotgun.lvl++;
		}
	}
	else if (isButtonPushed(window, upgrade3, x, y, event) == true && minigunIsUnlocked == true)
	{
		if (moneyy >= 100)
		{
			minigun.damage += 5;
			moneyy -= 100;
			minigun.lvl++;
		}
	}
	else if (isButtonPushed(window, upgrade2, x, y, event) == true && shotgunIsUnlocked == false)
	{
		if (moneyy >= 150)
		{
			shotgun.isUnlocked = true;
			moneyy -= 150;
			shotgun.lvl++;
		}
	}
	else if (isButtonPushed(window, upgrade3, x, y, event) == true && minigunIsUnlocked == false)
	{
		if (moneyy >= 150)
		{
			minigun.isUnlocked = true;
			moneyy -= 150;
			minigun.lvl++;
		}
	}

}

bool waveBreak::isMouseOver(sf::RenderWindow& window, sf::Sprite button, int x, int y)
{
	float mouseX = window.mapPixelToCoords(sf::Mouse::getPosition(window)).x;
	float mouseY = window.mapPixelToCoords(sf::Mouse::getPosition(window)).y;

	float buttonPosX = button.getPosition().x - button.getOrigin().x;
	float buttonPosY = button.getPosition().y - button.getOrigin().y;

	float buttonPosWidth = button.getPosition().x + button.getOrigin().x;
	float buttonPosHeight = button.getPosition().y + button.getOrigin().y;

	if (mouseX < buttonPosWidth && mouseX > buttonPosX && mouseY < buttonPosHeight && mouseY > buttonPosY)
	{
		return true;
	}
	else return false;
}

bool waveBreak::isButtonPushed(sf::RenderWindow& window, sf::Sprite button, int x, int y, sf::Event event)
{

	if (isMouseOver(window, button, x, y) == true && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return true;
	}
	else
	{
		return false;
	}
}