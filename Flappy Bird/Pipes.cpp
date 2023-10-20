#include "Pipes.h"

Pipes::Pipes() {

}

Pipes::Pipes(sf::RenderWindow* w) {
	gameWindow = w;

	pipeUpTex.loadFromFile("Resources/pipe-up.png");
	pipeDownTex.loadFromFile("Resources/pipe-down.png");

	pipeUpSprite.setTexture(pipeUpTex);
	pipeDownSprite.setTexture(pipeDownTex);

	sf::FloatRect pipeUpBounds = pipeUpSprite.getLocalBounds();
	sf::FloatRect pipeDownBounds = pipeDownSprite.getLocalBounds();

	pipeUpSprite.setOrigin(pipeUpBounds.left + pipeUpBounds.width / 2, pipeUpBounds.top + pipeUpBounds.height / 2);
	pipeDownSprite.setOrigin(pipeDownBounds.left + pipeDownBounds.width / 2, pipeDownBounds.top + pipeDownBounds.height / 2);

	pipeSpawnTimer = sf::Time::Zero;

	for (int i = 0; i < 8; i++) {
		pipes[i] == NULL;
	}
}

void Pipes::draw() {
	for (int i = 0; i < 8; i++) {
		if (pipes[i] != NULL) {
			gameWindow->draw(*pipes[i]);
		}
	}
}