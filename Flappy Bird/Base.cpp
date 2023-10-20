#include "Base.h"

Base::Base() {

}

Base::Base(sf::RenderWindow* w) {
	gameWindow = w;

	baseTex.loadFromFile("Resources/base.png");
	baseSprite.setTexture(baseTex);
}

void Base::update(sf::Time delta) {

}

void Base::draw() {

}