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
	for (auto s : scoreSprites) {
		delete s;
	}

	scoreSprites.clear();
	if (s != 0) {
		scoreSprites.resize(log10(s) + 1);

		int places = (int)log10(s) + 1;

		int sCopy = s;

		int placeInQuestion = places - 1;
		for (int i = 1; i <= places; i++) {
			int digit = sCopy % 10;
			sCopy /= 10;

			scoreSprites[placeInQuestion] = new sf::Sprite;
			sf::Sprite newSprite;
			newSprite.setTexture(digitTex[digit]);
			sf::FloatRect newBounds = newSprite.getLocalBounds();
			newSprite.setOrigin(newBounds.left + newBounds.width / 2, newBounds.top + newBounds.height / 2);
			*scoreSprites[placeInQuestion] = newSprite;
			placeInQuestion--;
		}
	}
	else {
		scoreSprites.resize(1);

		scoreSprites[0] = new sf::Sprite;
		sf::Sprite zeroSprite;
		zeroSprite.setTexture(digitTex[0]);
		sf::FloatRect zeroBounds = zeroSprite.getLocalBounds();
		zeroSprite.setOrigin(zeroBounds.left + zeroBounds.width / 2, zeroBounds.top + zeroBounds.height / 2);
		*scoreSprites[0] = zeroSprite;
	}
}

void Score::draw() {
	int startX = 153 - (scoreSprites.size() * scoreSprites[0]->getLocalBounds().width / 2);

	for (int i = 0; i < scoreSprites.size(); i++) {
		scoreSprites[i]->setPosition(sf::Vector2f(startX + (i * 30), 100));
		gameWindow->draw(*scoreSprites[i]);
	}
}