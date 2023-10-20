#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class Bird {
public:
	Bird();
	Bird(sf::RenderWindow* w);
	void update(sf::Time delta);
	void flap();
	void draw();
private:
	void updateAnimation();
	int birdSet, animIndex;
	sf::RenderWindow* gameWindow;
	sf::Vector2f velocity;

	sf::Texture birdTex[3][3];
	sf::Sprite birdSprite;
};