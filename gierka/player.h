#include <sfml/graphics.hpp>

class player
{
private:
	sf::Vector2f position;
	int width = 32;
	sf::Sprite body;
	sf::Texture playerTex1;
	float speed = 2;
public:
	player();
	void movePlayer(float x, float y);
	sf::Vector2f getPlayerPosition();
	sf::Sprite getPlayer();
	int getSpeed();
};



