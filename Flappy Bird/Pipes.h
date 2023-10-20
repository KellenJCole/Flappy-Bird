#pragma once
#include <SFML/Graphics.hpp>

class Pipes {
public:
	Pipes();
	Pipes(sf::RenderWindow* w);
	void updatePipes(sf::Time dt);
	void draw();
private:
	sf::RenderWindow* gameWindow;
	sf::Texture pipeUpTex, pipeDownTex;
	sf::Sprite pipeUpSprite, pipeDownSprite;
	sf::Time pipeSpawnTimer;
	sf::Sprite* pipes[8];
};