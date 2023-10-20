#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Pipes {
public:
	Pipes();
	Pipes(sf::RenderWindow* w);
	void updatePipes(sf::Time dt);
	void draw();
	std::vector<sf::RectangleShape> getCollision();
private:
	sf::RenderWindow* gameWindow;
	sf::Texture pipeUpTex, pipeDownTex;
	sf::Sprite pipeUpSprite, pipeDownSprite;
	sf::Time pipeSpawnTimer;
	sf::Sprite* pipes[8];
	std::vector<sf::RectangleShape> collisionBoxes;
};