#include "player.h"

void player::movePlayer(float x, float y)
{
	sf::Vector2f position;
	position.x = x;
	position.y = y;
	body.move(position);
}
player::player()
{
	playerTex1.loadFromFile("Textures/postac.png");
	body.setTexture(playerTex1);
	body.setPosition(500.f, 200.f);
}
sf::Vector2f player::getPlayerPosition()
{
	return body.getPosition();
}
sf::Sprite player::getPlayer()
{
	return body;
}
int player::getSpeed()
{
	return speed;
}
