#pragma once //do naprawy
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream> //Strumienie napisowe s¹ zestawem klas, które umo¿liwiaj¹ wykonywanie operacji na napisach (string) tak, jakby by³y one strumieniami. 
#define MAX_LICZBA_WERSOW_OPCJE 2

//definiuje nastepujace klawisze, aby po jego wcisnieciu nie otrzymac wartosci ASCII
#define DELETE 8 
#define ENTER 13


class nick
{
public:
	nick(float size, sf::Color color);//domyslny konstruktor - wielkosc i czy jest zaznaczone pole
	~nick();
	std::string getText() { return napis.str(); }

	void draw(sf::RenderWindow& window);
	void napisz_na(sf::Event input);
	void setFont(sf::Font& font);
	void setPosition(float width, float height);
	std::string returnNpis() { return napis.str(); }

private:
	sf::Text text; //wyswietlany text
	sf::Font font;
	std::ostringstream napis;
	 //aby dynamicznie edytowac tekst w oknie SFML, strumieñ dziedzicz¹cy po ostream, umo¿liwiaj¹cy jedynie zapis
	int limit = 8;
	sf::Texture background;

	//metoda do wprowadzania
	void wejscie(int typZnaku);//aby uzyskac dane wejsciowe od uzytkownika - typ znaku jest wartoscia ASCII zwracana przez SFML w zaleznosci od znaku

	//metoda do usuwania 
	void skasuj_znak();
};

