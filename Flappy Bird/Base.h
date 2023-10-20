#pragma once
#include <SFML/Graphics.hpp>

class Base {
public:
	Base();
	Base(sf::RenderWindow* w);
	void update(sf::Time delta);
	void draw();
private:
	sf::RenderWindow* gameWindow;

	sf::Texture baseTex;
	sf::Sprite baseSprite;
	
	sf::Sprite* baseSprites[2];
};