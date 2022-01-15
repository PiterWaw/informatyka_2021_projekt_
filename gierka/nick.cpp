#include "nick.h"

nick::nick(float size, sf::Color color)
{
	text.setCharacterSize(size);
	text.setFillColor(color);
}

nick::~nick()
{
}

void nick::draw(sf::RenderWindow& window)
{
	//window.clear();
	background.loadFromFile("pliki/obrazy/menu_test.png");
	sf::Sprite tlo;
	tlo.setTexture(background);
	tlo.setScale(sf::Vector2f(1.0f, 1.2f));
	window.draw(tlo);
	window.draw(text);
}

void nick::napisz_na(sf::Event input)
{
	int typZnaku = input.text.unicode; //typ znaku otrzyma wartosc unicode wpisywanego znaku z klawiatury
	if (typZnaku < 128) //czyli litery ukosniki kropki
	{
		if (napis.str().length() <= limit) //jak nie bedzie limit to wprowadzi ciag znakow
		{
			wejscie(typZnaku);
		}
		else if (napis.str().length() > limit && typZnaku == DELETE) //jak bedzie limit i wcisne DELETE to skasuje
		{
			skasuj_znak();
			std::cout << "Skasuj" << std::endl;
		}
	}
}

void nick::setFont(sf::Font& font)
{
	text.setFont(font);
}

void nick::setPosition(float width, float height)
{
	text.setPosition(sf::Vector2f(width, height));
}

void nick::wejscie(int typZnaku)
{
	if (typZnaku != DELETE && typZnaku != ENTER)
	{
		napis << static_cast<char>(typZnaku);//statyczne rzutowanie znaku na wpisana postac "typZnaku"
	}
	else if (typZnaku == DELETE)
	{
		if (napis.str().length() > 0)	//zabezpiecznie przed usuwaniem czegos, czego nie ma. .str() daje rzeczywista wartosc ciagu
		{
			skasuj_znak();
		}
	}
	text.setString(napis.str() + "_"); //"_" zeby sledzic gdzie jestem
}

void nick::skasuj_znak()
{
	std::string t = napis.str(); //lancuch
	std::string nowy_t = "";

	for (int i = 0; i < t.length() - 1; i++) //badam dlugosc napisu, i bede przypisywal znaki do nowego napisu z wyjatkiem ostatniego - stad -1
	{
		nowy_t += t[i];
	}
	napis.str(""); //czyszcze tekst, takie zachowanie zeby nie bylo widac petli wyzej
	napis << nowy_t; //zastepuje napis nowym (z usunietym znakiem)

	text.setString(napis.str());
}
























//
//	wers[0].setFont(font);
//	wers[0].setFillColor(sf::Color(0, 255, 0));
//	wers[0].setCharacterSize(50);
//	wers[0].setString("Wprowadz swoj nick (max 10 znakow: ");
//	wers[0].setPosition(sf::Vector2f(width / 6, height / (MAX_LICZBA_WERSOW_OPCJE + 3) * 1));
//
//	wers[1].setFont(font);
//	wers[1].setFillColor(sf::Color(0, 255, 0));
//	wers[1].setCharacterSize(50);
//	wers[1].setPosition(sf::Vector2f(width / 6, height / (MAX_LICZBA_WERSOW_OPCJE + 3) * 2 + 50));
//
//	wers[1].setString("Tu bedzie twoj nick: ");
//}
//
//void Menu_nickname::draw(sf::RenderWindow& window)
//{
//	//window.clear();
//	background.loadFromFile("pliki/obrazy/menu_test.png");
//	sf::Sprite tlo;
//	tlo.setTexture(background);
//	tlo.setScale(sf::Vector2f(1.0f, 1.2f));
//	window.draw(tlo);
//	for (int i = 0; i < MAX_LICZBA_WERSOW_OPCJE; i++)
//	{
//		window.draw(wers[i]);
//	}
//}
//
//void Menu_nickname::przesun_gora()
//{
//	if (selectedItem >= 0 && selectedItem < MAX_LICZBA_WERSOW_OPCJE)
//	{
//		wers[selectedItem].setFillColor(sf::Color(0, 255, 0));
//		wers[selectedItem].setStyle(sf::Text::Regular);
//		selectedItem--;
//		if (selectedItem <= 0)
//			selectedItem = MAX_LICZBA_WERSOW_OPCJE - 1;
//		if (selectedItem == 4)
//			selectedItem = 3;
//		wers[selectedItem].setFillColor(sf::Color::Cyan);
//	}
//}
//
//void Menu_nickname::przesun_dol()
//{
//	if (selectedItem >= 0 && selectedItem < MAX_LICZBA_WERSOW_OPCJE)
//	{
//		wers[selectedItem].setFillColor(sf::Color(0, 255, 0));
//		wers[selectedItem].setStyle(sf::Text::Regular);
//		selectedItem++;
//		if (selectedItem >= MAX_LICZBA_WERSOW_OPCJE)
//			selectedItem = 1;
//		if (selectedItem == 4)
//			selectedItem = 5;
//		wers[selectedItem].setFillColor(sf::Color::Cyan);
//	}
//}
//
//void Menu_nickname::zmien_kolor(int t, int d)
//{
//	wers[t].setFillColor(sf::Color::Red);
//	wers[d].setFillColor(sf::Color::Red);
//
//	for (int j = 0; j < MAX_LICZBA_WERSOW_OPCJE; j++)
//	{
//		if (wers[j].getFillColor() == sf::Color::Red && j != d && j != t)
//		{
//			wers[j].setFillColor(sf::Color(0, 255, 0));
//		}
//
//	}
//}
//
//
