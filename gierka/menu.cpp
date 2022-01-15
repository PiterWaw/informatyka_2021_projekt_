#include "menu.h"

menu::menu()
{
	button4.setTexture(buttonTex);
	button5.setTexture(buttonTex);
	leaderboard.setFont(font);
	leaderboard.setFillColor(sf::Color::Black);
	button4.setOrigin(96, 32);
	button5.setOrigin(96, 32);
	leaderboard.setCharacterSize(25);
	helpInfo.setFont(font);
	helpInfo.setFillColor(sf::Color::Black);
	helpInfo.setCharacterSize(25);
	nick.setFont(font);
	nick.setCharacterSize(25);
	nick.setFillColor(sf::Color::Black);
	if (isSelected)
	{
		nick.setString("_");
	}
	else
	{
		nick.setString("");
	}
}

void menu::menuDisplay(sf::RenderWindow& window, sf::Event event, int& menuStage, sf::View &view, bool &waveBreak)
{
	float x = window.getSize().x / 2;
	float y = window.getSize().y / 2;

	view.setCenter(x,y);
	window.setView(view);

	button1Hover.setFillColor(sf::Color(134, 134, 134, 80));
	button2Hover.setFillColor(sf::Color(134, 134, 134, 80));

	if (menuStage == 1)
	{
		button1.setPosition(x, y - 117);
		button2.setPosition(x, y - 39);
		button3.setPosition(x, y + 117);
		button4.setPosition(x, y + 39);
		resume.setString("NEW GAME");
		help.setString("HELP");
		exit.setString("EXIT");
		leaderboard.setString("LEADERBOARD");
		resume.setPosition(x - 75 , y - 135);
		help.setPosition(x - 35, y - 57);
		exit.setPosition(x - 32, y + 99);
		leaderboard.setPosition(x - 83, y + 26);
		window.clear(sf::Color(241, 221, 221));
		window.draw(button1);
		window.draw(button2);
		window.draw(button3);
		window.draw(money);
		window.draw(resume);
		window.draw(help);
		window.draw(exit);
		window.draw(button4);
		window.draw(leaderboard);
	}
	else if (menuStage == 2)
	{
		button1.setPosition(x - 170, y - 117);
		button2.setPosition(x - 170, y - 39);
		button3.setPosition(x - 170, y + 117);
		button4.setPosition(x - 170, y + 39);
		infoWaveBoxEmpty.setPosition(x + 150, y);
		resume.setString("GO BACK");
		help.setString("HELP");
		exit.setString("EXIT");
		leaderboard.setString("LEADERBOARD");
		helpInfo.setString("Move with: WSAD\n\nEarn money by killing\nthe enemies!\n\nChange weapon with buttons: 1, 2, 3");
		resume.setPosition(x - 232, y - 135);
		help.setPosition(x - 202, y - 57);
		exit.setPosition(x - 200, y + 99);
		leaderboard.setPosition(x - 253, y + 23);
		helpInfo.setPosition(x - 30 , y - 100);
		window.clear(sf::Color(241, 221, 221));
		window.draw(button1);
		window.draw(button2);
		window.draw(button3);
		window.draw(infoWaveBoxEmpty);	
		window.draw(money);
		window.draw(resume);
		window.draw(help);
		window.draw(exit);
		window.draw(button4);
		window.draw(leaderboard);
		window.draw(helpInfo);
	}
	else if (menuStage == 3)
	{
		button1.setPosition(x - 170, y - 117);
		button2.setPosition(x - 170, y - 39);
		button3.setPosition(x - 170, y + 117);
		button4.setPosition(x - 170, y + 39);
		infoWaveBoxEmpty.setPosition(x + 150, y);
		resume.setString("GO BACK");
		help.setString("HELP");
		exit.setString("EXIT");
		leaderboard.setString("LEADERBOARD");
		helpInfo.setString("1. ktos\n\n2. ktos inny\n\n3. jeszcze ktos inny");
		resume.setPosition(x - 232, y - 135);
		help.setPosition(x - 202, y - 57);
		exit.setPosition(x - 200, y + 99);
		leaderboard.setPosition(x - 253, y + 23);
		helpInfo.setPosition(x - 30, y - 100);
		window.clear(sf::Color(241, 221, 221));
		window.draw(button1);
		window.draw(button2);
		window.draw(button3);
		window.draw(infoWaveBoxEmpty);
		window.draw(money);
		window.draw(resume);
		window.draw(help);
		window.draw(exit);
		window.draw(button4);
		window.draw(leaderboard);
		window.draw(helpInfo);
	}
	else if (menuStage == 6)
	{
		
		button5.setPosition(x, y);
		infoWaveBoxEmpty.setPosition(x, y);
		resume.setString("GO BACK");
		helpInfo.setString("TYPE YOUR NAME: ");
		resume.setPosition(x-60, y-20);
		helpInfo.setPosition(x-100, y-150);
		window.clear(sf::Color(241, 221, 221));
		window.draw(button5);
		//window.draw(infoWaveBoxEmpty);
		window.draw(resume);
		window.draw(helpInfo);

		nick.setPosition(x - 50, y - 100);

		
	}

	
	if (menuStage != 6)
	{
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
		else if (isMouseOver(window, button4, x, y) == true)
		{
			button1Hover.setPosition(button4.getPosition().x, button4.getPosition().y);
			window.draw(button1Hover);
		}

		if (isButtonPushed(window, button1, x, y, event) == true && menuStage == 1)
		{
			menuStage = 6;
		}
		else if (isButtonPushed(window, button1, x, y, event) == true && menuStage != 1)
		{
			menuStage = 1;
		}
		else if (isButtonPushed(window, button2, x, y, event) == true)
		{
			menuStage = 2;
		}
		else if (isButtonPushed(window, button3, x, y, event) == true)
		{
			window.close();
		}
		else if (isButtonPushed(window, button4, x, y, event) == true)
		{
			menuStage = 3;
		}
	}
	else
	{
		if (isMouseOver(window, button5, x, y) == true)
		{
			button1Hover.setPosition(button5.getPosition().x, button5.getPosition().y);
			window.draw(button1Hover);
		}
		if (isButtonPushed(window, button5, x, y, event) == true && menuStage == 6)
		{
			menuStage = 4;
		}
	}
	
	waveBreak = false;
}

void menu::inputLogic(int charTyped)
{
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
	{
		nickStream << static_cast<char>(charTyped);
	}
	else if (charTyped == DELETE_KEY)
	{
		if (nickStream.str().length() > 0)
		{
			deleteLastChar();
		}
	}
	nick.setString(nickStream.str() + "_");
}

void menu::deleteLastChar()
{
	std::string t = nickStream.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
	}
	nickStream.str("");
	nickStream << newT;

	nick.setString(nickStream.str());
}

void menu::setSelected(bool sel)
{
	isSelected = sel;
	if (!sel)
	{
		std::string t = nickStream.str();
		std::string newT = "";
		for (int i = 0; i < t.length() - 1; i++)
		{
			newT += t[i];
		}
		nick.setString(newT);

	}	
}
std::string menu::getText()
{
	return nickStream.str();
}
void menu::drawTo(sf::RenderWindow& window)
{
	window.draw(nick);
}
void menu::typedOn(sf::Event input)
{
	if (isSelected)
	{
		int charTyped = input.text.unicode;
		
			inputLogic(charTyped);
			if (charTyped == DELETE_KEY)
			{
				deleteLastChar();
			}
	}
}