#include "CollisionDetector.h"

CollisionDetector::CollisionDetector() {

}

bool CollisionDetector::isColliding(sf::RectangleShape a, sf::RectangleShape b) {
	return a.getGlobalBounds().intersects(b.getGlobalBounds()) ? true : false;
}