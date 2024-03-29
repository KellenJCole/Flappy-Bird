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
	sf::RectangleShape getCollision();
	void reset();
private:
	void updateAnimation(sf::Time delta);
	int birdSet, animIndex;

	sf::RenderWindow* gameWindow;
	sf::Vector2f velocity;

	sf::Texture birdTex[3][3];
	sf::Sprite birdSprite;

	sf::Time animClock;

	float rotationSpeed;

	// sound
	sf::SoundBuffer buffer;
	sf::Sound flapSound;

	// collision
	sf::RectangleShape birdCollBox;
};