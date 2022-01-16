#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <iostream>
#include "mapa.h"
#include "weapon.h"
#include "enemy.h"
#include "bullet.h"
#include <vector>
#include <math.h>
#include "shotting.h"
#include "enemySpawner.h"
#include "HUD.h"
#include "waveBreak.h"
#include "gameOver.h"
#include "menu.h"
#include "nick.h"



#pragma warning(disable : 4996)



typedef struct {
	char name[20];
	int score;
} dataStruct;

class data
{
public:
	dataStruct s1[3];

	FILE* file;

	void save(std::string name, int score);
	void read();
	data();

	const char* PERSON_OUT = "(%s, %d)\n";
	const char* PERSON_IN = "(%s, %d)\n";
};

data::data()
{

}

void data::save(std::string name, int score)
{
	//read();

	fopen_s(&file, "leaderboard.dat", "w+");

	if (score > s1[2].score)
	{
		if (score > s1[1].score)
		{
			if (score > s1[0].score)
			{
				s1[0].score = score;
				strcpy(s1[0].name, name.c_str());
			}
			else
			{
				s1[1].score = score;
				strcpy(s1[1].name, name.c_str());
			}
		}
		else
		{
			s1[2].score = score;
			strcpy(s1[2].name, name.c_str());
		}
	}

	for (int i = 0; i < 3; i++)
	{
		//fwrite(s1, sizeof(s1), 3, file);
		fprintf_s(file, PERSON_OUT, s1[i].name, s1[i].score);
	}
	fclose(file);
}

void data::read()
{
	//file = fopen("leaderboard.dat", "r");
	fopen_s(&file, "leaderboard.dat", "r");

	fseek(file, 0, SEEK_SET);
	for (int i = 0; i < 3; i++)
	{
		//fread(s1, sizeof(s1), 3, file);		
		fscanf_s(file, s1[i].name, 20, s1[i].score);
	}

	fclose(file);
}

int main()
{
	sf::RenderWindow gra(sf::VideoMode(1920, 1080), "Gierka Alpha v0.1", sf::Style::Fullscreen); //1280, 768

	gra.setKeyRepeatEnabled(false);

	sf::Clock lag;

	player player1;
	float speed;
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(1920, 1080));
	view.setCenter(sf::Vector2f(player1.getPlayerPosition().x + 32, player1.getPlayerPosition().y + 32));
	sf::Vector2f mouse_pos;
	int movementSpeedLeft = player1.getSpeed();
	int movementSpeedRight = player1.getSpeed();
	int movementSpeedUp = player1.getSpeed();
	int movementSpeedDown = player1.getSpeed();

	gra.setFramerateLimit(60);
	mapa mapa1;
	weapon m4a4;
	weapon shotgun;
	weapon minigun;
	shotting shotting;
	enemySpawner enemySpawner;
	HUD HUD;
	waveBreak waveBreak;
	gameOver gameOver;
	menu menu;
	data data;
	nick nick(20, sf::Color::Black);
	mapa1.loadFiles();
	int whichWeapon = 1;

	sf::Music music;
	music.openFromFile("Sounds/music.wav");

	sf::Font font;
	font.loadFromFile("font.ttf");
	nick.setFont(font);
	sf::SoundBuffer deathb;
	sf::Sound deaths;
	deathb.loadFromFile("Sounds/dead.wav");
	deaths.setBuffer(deathb);
	bool deathp = false;
	

	m4a4.maxAmmo = 30;
	m4a4.ammo = 30;
	m4a4.damage = 45;
	m4a4.fireRate = 150;
	m4a4.isUnlocked = true;

	shotgun.maxAmmo = 5;
	shotgun.ammo = 5;
	shotgun.damage = 200;
	shotgun.fireRate = 1500;
	shotgun.isUnlocked = true;

	minigun.maxAmmo = 100;
	minigun.ammo = 100;
	minigun.damage = 15;
	minigun.fireRate = 60;
	minigun.isUnlocked = true;


	int HUDx = player1.getPlayerPosition().x;
	int HUDy = player1.getPlayerPosition().y;
	int sizeX = mapa1.getSizeX();
	int sizeY = mapa1.getSizeY();
	int firstWaveLag = 0;
	int firstWaveLaggg = 0;
	int menuStage = 1;
	bool resetAmmo = false;
	bool saveResaults = false;
	bool waveBreaks = false;

	sf::Event event;
	
	music.play();
	music.setVolume(10);

	while (gra.isOpen())
	{
		
		while (gra.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				gra.close();
				break;
			}
		}
		if (menuStage == 6)
		{
			menu.menuDisplay(gra, event, menuStage, view, waveBreaks);
			
			if (event.type == sf::Event::TextEntered) nick.napisz_na(event);

			
			nick.setPosition(menu.button4.getPosition().x-40, menu.button4.getPosition().y-120);
			nick.draw(gra);
			std::cout << nick.returnNpis() <<" " << menuStage<<  std::endl;


			//menu.drawTo(gra);
			//std::cout << menu.nickStream.str() << std::endl;
		}
		else if (menuStage == 1 || menuStage == 2 || menuStage == 3)
		{
			if (saveResaults == true)
			{
				data.save("piotrek", enemySpawner.wave - 10);
			}
			menu.menuDisplay(gra, event, menuStage, view, waveBreaks);

			player1.hp = player1.hpMax;
			player1.body.setPosition(500.f, 200.f);
			enemySpawner.wave = 10;
			enemySpawner.xDmg = 1;
			enemySpawner.enemies.clear();
			shotting.bullets.clear();
			m4a4.damage = 45;
			shotgun.damage = 200;
			minigun.damage = 15;
			waveBreaks = false;
			enemySpawner.extraSpawn = 1;
			enemySpawner.howManySpawned = 0;
			firstWaveLag = 0;
			m4a4.lvl = 1;
			shotgun.lvl = 0;
			minigun.lvl = 0;
			enemySpawner.money = 0;
			menu.nickStream.str() = "";
			deathp = false;
		}
		else if (menuStage == 5)
		{
			if (deathp == false)
			{
				deathp = true;
				deaths.play();
			}
			gameOver.gameOverDisplay(gra, HUDx, HUDy, event, enemySpawner.wave, menuStage, saveResaults);		
		}
		
		else
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
			{
				gra.close();
			}

			gra.setView(view);
			HUDx = player1.getPlayerPosition().x;
			HUDy = player1.getPlayerPosition().y;

			sf::Vector2f posForEnemies = sf::Vector2f(HUDx, HUDy);

			if (player1.hp < 0)
			{
				menuStage = 5;
				
			}

			if (waveBreaks == true || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				waveBreaks = true;
				gra.clear(sf::Color(241, 221, 221));

				for (int i = 0; i < sizeX; i++)
				{
					for (int j = 0; j < sizeY; j++)
					{
						gra.draw(mapa1.loadTile(i, j));
					}
				}
				HUD.hudDisplay(gra, HUDx, HUDy, shotgun, shotgun.isLoaded, player1.hp, player1.hpMax, whichWeapon, enemySpawner.enemies.size(), enemySpawner.wave, shotgun.isUnlocked, minigun.isUnlocked, nick.returnNpis(), player1.getPlayerPosition().x, player1.getPlayerPosition().y);

				waveBreak.waveBreakDisplay(gra, HUDx, HUDy, m4a4, shotgun, minigun, enemySpawner.money, shotgun.isUnlocked, minigun.isUnlocked, waveBreaks, event, resetAmmo, menuStage);

				//path.pathUpdate(mapa1);

			}
			else
			{
				speed = player1.getSpeed();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player1.movePlayer(-movementSpeedLeft, 0.f);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player1.movePlayer(0.f, movementSpeedDown);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player1.movePlayer(movementSpeedRight, 0.f);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player1.movePlayer(0.f, -movementSpeedUp);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && m4a4.isUnlocked == true)
				{
					if (whichWeapon != 1)
					{
						shotting.isFirstShot = true;
						m4a4.reloadColdown.restart();
					}
					whichWeapon = 1;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && shotgun.isUnlocked == true)
				{
					if (whichWeapon != 2)
					{
						shotting.isFirstShot = true;
						shotgun.reloadColdown.restart();
					}
					whichWeapon = 2;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && minigun.isUnlocked == true)
				{
					if (whichWeapon != 3)
					{
						shotting.isFirstShot = true;
						minigun.reloadColdown.restart();
					}
					whichWeapon = 3;
				}

				gra.clear(sf::Color(241, 221, 221));


				for (int i = 0; i < sizeX; i++)
				{
					for (int j = 0; j < sizeY; j++)
					{
						gra.draw(mapa1.loadTile(i, j));
					}
				}

				movementSpeedLeft = mapa1.collisionLeft(player1);
				movementSpeedRight = mapa1.collisionRight(player1);
				movementSpeedUp = mapa1.collisionUp(player1);
				movementSpeedDown = mapa1.collisionDown(player1);

				gra.draw(player1.getPlayer());

				mouse_pos = gra.mapPixelToCoords(sf::Mouse::getPosition(gra));





				if (whichWeapon == 1)
				{
					m4a4.changeWeapon(whichWeapon);

					m4a4.updatePos(sf::Vector2f(player1.getPlayerPosition()), mouse_pos);
					gra.draw(m4a4.getWeapon());

					view.setCenter(sf::Vector2f(player1.getPlayerPosition().x + 32, player1.getPlayerPosition().y + 32));

					enemySpawner.enemyCollision(shotting, shotting.b1.damage, posForEnemies, mapa1, player1);
					enemySpawner.enemySpawn(waveBreaks, firstWaveLag, player1, resetAmmo);
					enemySpawner.enemyDraw(gra);

					shotting.bulletCollision(mapa1);
					shotting.shottingUpdate(gra, mouse_pos, m4a4.weaponBody.getPosition(), mapa1, m4a4, whichWeapon);

					HUD.hudDisplay(gra, HUDx, HUDy, m4a4, m4a4.isLoaded, player1.hp, player1.hpMax, whichWeapon, enemySpawner.enemies.size(), enemySpawner.wave, shotgun.isUnlocked, minigun.isUnlocked, nick.returnNpis(), player1.getPlayerPosition().x, player1.getPlayerPosition().y);
				}
				else if (whichWeapon == 2)
				{
					shotgun.changeWeapon(whichWeapon);

					shotgun.updatePos(sf::Vector2f(player1.getPlayerPosition()), mouse_pos);
					gra.draw(shotgun.getWeapon());

					view.setCenter(sf::Vector2f(player1.getPlayerPosition().x + 32, player1.getPlayerPosition().y + 32));

					enemySpawner.enemyCollision(shotting, shotgun.damage, posForEnemies, mapa1, player1);
					enemySpawner.enemySpawn(waveBreaks, firstWaveLag, player1, resetAmmo);
					enemySpawner.enemyDraw(gra);

					shotting.bulletCollision(mapa1);
					shotting.shottingUpdate(gra, mouse_pos, shotgun.weaponBody.getPosition(), mapa1, shotgun, whichWeapon);

					HUD.hudDisplay(gra, HUDx, HUDy, shotgun, shotgun.isLoaded, player1.hp, player1.hpMax, whichWeapon, enemySpawner.enemies.size(), enemySpawner.wave, shotgun.isUnlocked, minigun.isUnlocked, nick.returnNpis(), player1.getPlayerPosition().x, player1.getPlayerPosition().y);
				}
				else if (whichWeapon == 3)
				{
					minigun.changeWeapon(whichWeapon);

					minigun.updatePos(sf::Vector2f(player1.getPlayerPosition()), mouse_pos);
					gra.draw(minigun.getWeapon());

					view.setCenter(sf::Vector2f(player1.getPlayerPosition().x + 32, player1.getPlayerPosition().y + 32));

					enemySpawner.enemyCollision(shotting, minigun.damage, posForEnemies, mapa1, player1);
					enemySpawner.enemySpawn(waveBreaks, firstWaveLag, player1, resetAmmo);
					enemySpawner.enemyDraw(gra);

					shotting.bulletCollision(mapa1);
					shotting.shottingUpdate(gra, mouse_pos, minigun.weaponBody.getPosition(), mapa1, minigun, whichWeapon);

					HUD.hudDisplay(gra, HUDx, HUDy, minigun, minigun.isLoaded, player1.hp, player1.hpMax, whichWeapon, enemySpawner.enemies.size(), enemySpawner.wave, shotgun.isUnlocked, minigun.isUnlocked, nick.returnNpis(), player1.getPlayerPosition().x, player1.getPlayerPosition().y);
				}
			}		
		}
		gra.display();
	}
}
