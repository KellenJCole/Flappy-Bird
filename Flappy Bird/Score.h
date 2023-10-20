#pragma once
#include <SFML/Graphics.hpp>

class Score {
public:
	Score();
	Score(sf::RenderWindow* w);
	void setScore(int s);
	void draw();
private:
	sf::RenderWindow* gameWindow;
	sf::Texture digitTex[10];
	std::vector<sf::Sprite*> scoreSprites;
};