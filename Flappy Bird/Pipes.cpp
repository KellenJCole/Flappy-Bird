#include "Pipes.h"

Pipes::Pipes() {

}

Pipes::Pipes(sf::RenderWindow* w) {
	srand(time(NULL));
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
		pipes[i] = NULL;
	}

	collisionBoxes.resize(8);
	pointCollisionBoxes.resize(4);
}

void Pipes::draw() {
	for (int i = 0; i < 8; i++) {
		if (pipes[i] != NULL) {
			gameWindow->draw(*pipes[i]);
		}
	}
}

void Pipes::updatePipes(sf::Time dt) {
	pipeSpawnTimer += dt;

	// Despawn pipes out of view

	for (int i = 0; i < 8; i += 2) {
		if (pipes[i] != NULL) {
			sf::Vector2f pipePosition = pipes[i]->getPosition();
			if (pipePosition.x < -50) {
				pipes[i] = NULL;
				pipes[i + 1] = NULL;
			}
		}
	}

	if (pipeSpawnTimer > sf::milliseconds(2000)) { // Spawn pipe
		pipeSpawnTimer = sf::Time::Zero;

		for (int i = 0; i < 8; i += 2) {
			if (pipes[i] == NULL) { // Found place to spawn pipe
				pipes[i] = new sf::Sprite(pipeUpSprite);
				pipes[i + 1] = new sf::Sprite(pipeDownSprite);

				collisionBoxes[i].setSize(sf::Vector2f(pipes[i]->getLocalBounds().width, pipes[i]->getLocalBounds().height));
				collisionBoxes[i].setOrigin(pipes[i]->getOrigin());
				collisionBoxes[i + 1].setSize(sf::Vector2f(pipes[i + 1]->getLocalBounds().width, pipes[i + 1]->getLocalBounds().height));
				collisionBoxes[i + 1].setOrigin(pipes[i + 1]->getOrigin());

				int pipeSpawnX = 400;
				int pipeUpSpawnY = 300 + rand() % 250;
				int pipeDownSpawnY = pipeUpSpawnY - 450;

				pointCollisionBoxes[i / 2].setSize(sf::Vector2f(pipes[i]->getLocalBounds().width / 2, 130));
				sf::FloatRect pointCollisionRect = pointCollisionBoxes[i / 2].getLocalBounds();
				pointCollisionBoxes[i / 2].setOrigin(pointCollisionRect.left + pointCollisionRect.width / 2, pointCollisionRect.top + pointCollisionRect.height / 2);
				pointCollisionBoxes[i / 2].setPosition(sf::Vector2f(pipeSpawnX, pipeDownSpawnY - 225));

				pipes[i]->setPosition(pipeSpawnX, pipeUpSpawnY);
				pipes[i + 1]->setPosition(pipeSpawnX, pipeDownSpawnY);

				collisionBoxes[i].setPosition(pipeSpawnX, pipeUpSpawnY);
				collisionBoxes[i + 1].setPosition(pipeSpawnX, pipeDownSpawnY);
				break;
			}
		}
	}

	// Make pipes move
	float scrollSpeed = -100.f;
	float distanceToMove = scrollSpeed * dt.asSeconds();

	for (int i = 0; i < 8; i++) {
		if (pipes[i] != NULL) {
			sf::Vector2f pipePosition = pipes[i]->getPosition();
			pipePosition.x += distanceToMove;
			pipes[i]->setPosition(pipePosition);
			collisionBoxes[i].setPosition(pipePosition);
			if (i % 2 == 0) {
				pointCollisionBoxes[i / 2].setPosition(pipePosition.x, pipePosition.y - 225);
			}
		}
	}
}

std::vector<sf::RectangleShape> Pipes::getCollision() {
	return collisionBoxes;
}

void Pipes::reset() {
	for (int i = 0; i < 8; i++) {
		pipes[i] = NULL;
	}

	pipeSpawnTimer = sf::Time::Zero;
	collisionBoxes.clear();
	collisionBoxes.resize(8);
	pointCollisionBoxes.clear();
	pointCollisionBoxes.resize(4);
}

std::vector<sf::RectangleShape> Pipes::getPointCollision() {
	return pointCollisionBoxes;
}