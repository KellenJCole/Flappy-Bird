#include "Base.h"

Base::Base() {

}

Base::Base(sf::RenderWindow* w) {
	gameWindow = w;

	baseTex.loadFromFile("Resources/base.png");
	baseSprite.setTexture(baseTex);

	baseSprites[0] = new sf::Sprite(baseSprite);
	baseSprites[1] = new sf::Sprite(baseSprite);

	baseSprites[0]->setPosition(0, 400);
	baseSprites[1]->setPosition(336, 400);
}

void Base::update(sf::Time delta) {

	// First check if a sprite is completely out of view
	if (baseSprites[0]->getPosition().x < -336) {
		// If so, move the sprite behind the one following it and adjust index accordingly
		baseSprites[0]->setPosition(baseSprites[1]->getPosition().x + 336, 400);
		std::swap(baseSprites[0], baseSprites[1]);
	}
	float scrollSpeed = -100.f; // Adjust the rate at which the ground appears to pass the bird
	float distanceToScroll = scrollSpeed * delta.asSeconds(); // Use linear interpolation to calculate distance to move ground based off time passed

	// Adjust ground position accordingly
	baseSprites[0]->setPosition(baseSprites[0]->getPosition().x + distanceToScroll, 400);
	baseSprites[1]->setPosition(baseSprites[1]->getPosition().x + distanceToScroll, 400);
}

void Base::draw() {
	gameWindow->draw(*baseSprites[0]);
	gameWindow->draw(*baseSprites[1]);
}