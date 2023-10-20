#pragma once
#include <SFML/Audio.hpp>
#include "Base.h"
#include "Bird.h"
#include "Pipes.h"
#include "CollisionDetector.h"

class GameLoop {
public:
	GameLoop();
	void run();
private:
	void processEvents();
	void update(sf::Time delta);
	void render();

	sf::RenderWindow window;

	sf::Texture bgTexDay;
	sf::Texture bgTexNight;
	sf::Texture readyTex;
	sf::Texture gameOverTex;

	sf::Sprite bgSprite;
	sf::Sprite readySprite;
	sf::Sprite gameOverSprite;

	sf::SoundBuffer scoreBuffer;
	sf::SoundBuffer collisionBuffer;
	sf::Sound scoreSound;
	sf::Sound collisionSound;

	Base* ground;
	Bird* birdy;
	Pipes* pipe;

	sf::RectangleShape baseCollisionBox;

	CollisionDetector cd;

	bool gameOver;

	int score;
	sf::Time timeSinceScored;
};