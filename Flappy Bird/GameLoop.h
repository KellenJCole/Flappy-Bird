#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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
};