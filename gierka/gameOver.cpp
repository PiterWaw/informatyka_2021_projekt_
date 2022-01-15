#include "gameOver.h"

gameOver::gameOver()
{
	lastInfoText.setFont(font);
	lastInfoText.setFillColor(sf::Color::Black);
}

void gameOver::gameOverDisplay(sf::RenderWindow &window, int x, int y, sf::Event event, int waveNum, int& menuStage, bool &saveResaults)
{
	lastInfoString = "You survived: " + std::to_string(waveNum-10) + " waves\n\n\n" + "Best surivor: 10 waves";
	lastInfoText.setString(lastInfoString);
	lastInfoText.setPosition(x, y - 80);
	button1Hover.setFillColor(sf::Color(134, 134, 134, 80));
	button2Hover.setFillColor(sf::Color(134, 134, 134, 80));
	button1.setPosition(x - 170, y - 117);
	button2.setPosition(x - 170, y);
	button3.setPosition(x - 170, y + 117);
	infoWaveBoxEmpty.setPosition(x + 150, y);
	resume.setString("MENU");
	help.setString("HELP");
	exit.setString("EXIT");
	resume.setPosition(x - 213, y - 135); 
	help.setPosition(x - 205, y - 18);
	exit.setPosition(x - 200, y + 99);
	window.clear(sf::Color(241, 221, 221));
	window.draw(button1);
	window.draw(button2);
	window.draw(button3);
	window.draw(infoWaveBoxEmpty);
	window.draw(money);
	window.draw(resume);
	window.draw(help);
	window.draw(exit);
	window.draw(lastInfoText);

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

	if (isButtonPushed(window, button1, x, y, event) == true)
	{
		menuStage = 1;
		saveResaults = true;
	}
	else if (isButtonPushed(window, button2, x, y, event) == true)
	{
		window.draw(infoWaveBoxEmpty);
		window.draw(helpInfo);
	}
	else if (isButtonPushed(window, button3, x, y, event) == true)
	{
		window.close();		
	}
}

