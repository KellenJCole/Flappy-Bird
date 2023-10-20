#include "CollisionDetector.h"

CollisionDetector::CollisionDetector() {

}

bool CollisionDetector::isColliding(sf::RectangleShape a, sf::RectangleShape b) {
	if (a.getGlobalBounds().intersects(b.getGlobalBounds())) {
		return true;
	}
	return false;
}