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

}

void Base::draw() {
	gameWindow->draw(*baseSprites[0]);
	gameWindow->draw(*baseSprites[1]);
}