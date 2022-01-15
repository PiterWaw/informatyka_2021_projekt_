#include <sfml/graphics.hpp>

class player
{
public:
	sf::Vector2f position;
	int width = 32;
	
	sf::Texture playerTex1;
	float speed = 2;

	sf::Sprite body;
	int hpMax = 100;
	int hp = hpMax;
	player();
	void movePlayer(float x, float y);
	sf::Vector2f getPlayerPosition();
	sf::Sprite getPlayer();
	int getSpeed();
	void changeHP(int damage) { hp -= damage; }
	void resetHP() { hp = hpMax; }
};



