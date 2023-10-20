#pragma once
#include <SFML/Audio.hpp>
#include "Base.h"
#include "Bird.h"
#include "Pipes.h"

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
	
	sf::Sprite bgSprite;

	Base* ground;
	Bird* birdy;
	Pipes* pipe;
};