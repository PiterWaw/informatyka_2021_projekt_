#include "HUD.h"
#include <iostream>

HUD::HUD()
{
	ammoBoxTex.loadFromFile("Textures/ammoHUD.png");
	ammoBox.setTexture(ammoBoxTex);
	ammoBox.setPosition(50, 1000);	

	font.loadFromFile("font.ttf");
	ammoCount.setFont(font);
	ammoCount.setFillColor(sf::Color::Black);

	hpBoxTex.loadFromFile("Textures/hpHUD.png");
	hpBox.setTexture(hpBoxTex);
	hpBox.setPosition(50, 1000);

	hpCount.setFont(font);
	hpCount.setFillColor(sf::Color::Black);

	weaponBoxTex.loadFromFile("Textures/weaponHUD.png");
	weaponBox.setTexture(weaponBoxTex);
	weaponBox.setPosition(50, 1000);

	weaponNumber1.setFont(font);
	weaponNumber1.setFillColor(sf::Color::Black);
	weaponNumber2.setFont(font);
	weaponNumber2.setFillColor(sf::Color::Black);
	weaponNumber3.setFont(font);
	weaponNumber3.setFillColor(sf::Color::Black);

	m4a4BoxTex.loadFromFile("Textures/bron.png");
	m4a4Box.setTexture(m4a4BoxTex);
	shotgunBoxTex.loadFromFile("Textures/shotgun.png");
	shotgunBox.setTexture(shotgunBoxTex);
	minigunBoxTex.loadFromFile("Textures/minigun.png");
	minigunBox.setTexture(minigunBoxTex);
	minigunBox.setScale(0.9, 0.9);

	chosenWeapon.setSize(sf::Vector2f(55, 55));
	chosenWeapon.setOutlineThickness(2);
	chosenWeapon.setOutlineColor(sf::Color::Black);
	chosenWeapon.setFillColor(sf::Color::Transparent);

	zombieBoxTex.loadFromFile("Textures/enemy.png");
	zombieBox.setTexture(zombieBoxTex);
	zombieBox.setScale(0.7, 0.7);
	zombieCount.setFont(font);
	zombieCount.setFillColor(sf::Color::Black);

	waveInfo.setFont(font);
	waveInfo.setFillColor(sf::Color::Black);
	waveInfo.setLetterSpacing(2);
}

void HUD::hudDisplay(sf::RenderWindow& window, int x, int y, weapon weapon, bool isLoaded, int hp, int hpMax, int whichWeapon, int howManyZombie, int whichWave, bool shotgun, bool minigun)
{
	int ammo = weapon.ammo;
	int ammoMax = weapon.maxAmmo;
	if (isLoaded == false) ammoDisplay = "R / " + std::to_string(ammoMax);
	if (isLoaded == true) ammoDisplay = std::to_string(ammo) + " / " + std::to_string(ammoMax);
	ammoCount.setString(ammoDisplay);
	ammoBox.setPosition(x + 32 - 900, y + 32 + 450);
	ammoCount.setPosition(x + 32 - 840, y + 32 + 460);
	window.draw(ammoBox);
	window.draw(ammoCount);

	hpDisplay = std::to_string(hp) + " / " + std::to_string(hpMax);
	hpCount.setString(hpDisplay);
	hpBox.setPosition(x + 32 + 860, y + 32 + 452);
	hpCount.setPosition(x + 32 + 725, y + 32 + 460);
	window.draw(hpBox);
	window.draw(hpCount);


	weaponBox.setPosition(x - 80, y + 32 + 430);
	weaponNumber1.setPosition(weaponBox.getPosition().x + 21 + 5, weaponBox.getPosition().y - 30);
	weaponNumber1.setString("1");
	weaponNumber1.setCharacterSize(20);
	weaponNumber1.setStyle(sf::Text::Bold);
	weaponNumber2.setPosition(weaponBox.getPosition().x + 21 + 64 + 5, weaponBox.getPosition().y - 30);
	weaponNumber2.setString("2");
	weaponNumber2.setCharacterSize(20);
	weaponNumber2.setStyle(sf::Text::Bold);
	weaponNumber3.setPosition(weaponBox.getPosition().x + 21 + 64 + 64 + 5, weaponBox.getPosition().y - 30);
	weaponNumber3.setString("3");
	weaponNumber3.setCharacterSize(20);
	weaponNumber3.setStyle(sf::Text::Bold);
	window.draw(weaponBox);
	window.draw(weaponNumber1);
	window.draw(weaponNumber2);
	window.draw(weaponNumber3);

	m4a4Box.setPosition(weaponBox.getPosition().x + 14, weaponBox.getPosition().y + 25);
	shotgunBox.setPosition(weaponBox.getPosition().x + 10 + 64, weaponBox.getPosition().y + 25);
	minigunBox.setPosition(weaponBox.getPosition().x + 8 + 64 + 64, weaponBox.getPosition().y + 23);
	if (whichWeapon == 1) chosenWeapon.setPosition(weaponBox.getPosition().x + 6, weaponBox.getPosition().y + 5);
	if (whichWeapon == 2) chosenWeapon.setPosition(weaponBox.getPosition().x + 4 + 64, weaponBox.getPosition().y + 5);
	if (whichWeapon == 3) chosenWeapon.setPosition(weaponBox.getPosition().x + 4 + 64 + 64, weaponBox.getPosition().y + 5);
	window.draw(m4a4Box);
	if(shotgun == true) window.draw(shotgunBox);
	if (minigun == true) window.draw(minigunBox);
	window.draw(chosenWeapon);

	zombieBox.setPosition(x + 37 + 860, y - 472);
	zombieDisplay = std::to_string(howManyZombie);
	zombieCount.setString(zombieDisplay);
	zombieCount.setPosition(x + 840, y - 468);
	window.draw(zombieBox);
	window.draw(zombieCount);

	waveInfoString = "Wave:  " + std::to_string(whichWave-9);
	waveInfo.setString(waveInfoString);
	waveInfo.setPosition(x - 870, y - 468);
	window.draw(waveInfo);
}
