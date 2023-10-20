#pragma once
#include <SFML/Graphics.hpp>

class CollisionDetector {
public:
	CollisionDetector();
	bool isColliding(sf::RectangleShape a, sf::RectangleShape b);
};