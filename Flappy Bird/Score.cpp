#include "Score.h"

Score::Score() {

}

Score::Score(sf::RenderWindow* w) {
	gameWindow = w;

	for (int i = 0; i < 10; i++) {
		digitTex[i].loadFromFile("Resources/" + std::to_string(i) + ".png");
	}
}

void Score::setScore(int s) {

	if (s <= 9) {
		scoreSprites.resize(1);
		scoreSprites[0] = new sf::Sprite;
		sf::Sprite onesSprite;
		onesSprite.setTexture(digitTex[s]);
		sf::FloatRect onesBounds = onesSprite.getLocalBounds();
		onesSprite.setOrigin(onesBounds.left + onesBounds.width / 2, onesBounds.top + onesBounds.height / 2);
		*scoreSprites[0] = onesSprite;
	}
	else {
		bool makeNewDigitsPlace = true;
		int base = 10;
		while (makeNewDigitsPlace) {
			if (s >= base) {

			}
			else {
				makeNewDigitsPlace = false;
			}
			base *= 10;
		}
	}
}

void Score::draw() {
	int startX = 153 - (scoreSprites.size() * scoreSprites[0]->getLocalBounds().width / 2);

	for (int i = 0; i < scoreSprites.size(); i++) {
		scoreSprites[i]->setPosition(sf::Vector2f(startX, 100));
		gameWindow->draw(*scoreSprites[i]);
	}
}