#include "Bird.h"

Bird::Bird() {

}

Bird::Bird(sf::RenderWindow* w) {
	srand(time(NULL));

	gameWindow = w;

	birdTex[0][0].loadFromFile("Resources/yellowbird-downflap.png");
	birdTex[0][1].loadFromFile("Resources/yellowbird-midflap.png");
	birdTex[0][2].loadFromFile("Resources/yellowbird-upflap.png");
	birdTex[1][0].loadFromFile("Resources/redbird-downflap.png");
	birdTex[1][1].loadFromFile("Resources/redbird-midflap.png");
	birdTex[1][2].loadFromFile("Resources/redbird-upflap.png");
	birdTex[2][0].loadFromFile("Resources/bluebird-downflap.png");
	birdTex[2][1].loadFromFile("Resources/bluebird-midflap.png");
	birdTex[2][2].loadFromFile("Resources/bluebird-upflap.png");

	birdSet = rand() % 3;

	birdSprite.setTexture(birdTex[birdSet][1]);
	animIndex = 1;
	sf::FloatRect birdBounds = birdSprite.getLocalBounds();
	birdSprite.setOrigin(birdBounds.left + birdBounds.width / 2, birdBounds.top + birdBounds.height / 2);

	birdSprite.setPosition(80, 200);

	velocity.y = 250.f;

	animClock = sf::Time::Zero;

	rotationSpeed = 350.f;

	buffer.loadFromFile("Resources/wing.wav");
	flapSound.setBuffer(buffer);
	birdCollBox.setSize(sf::Vector2f(birdSprite.getLocalBounds().width, birdSprite.getLocalBounds().height));
	birdCollBox.setOrigin(birdSprite.getOrigin());
}

void Bird::update(sf::Time delta) {
	float deltaDistance = delta.asSeconds() * velocity.y;
	sf::Vector2f position = birdSprite.getPosition();
	position.y += deltaDistance;
	birdSprite.setPosition(position);
	birdCollBox.setPosition(birdSprite.getPosition());
	
	velocity.y += 3.5f;

	updateAnimation(delta);
}

void Bird::draw() {
	gameWindow->draw(birdSprite);
}

void Bird::flap() {
	velocity.y = -400.f;
	flapSound.play();
}

void Bird::updateAnimation(sf::Time delta) {
	float deltaRotation;
	animClock += delta;
	if (velocity.y < 0) { // If bird is rising, flap wings
		if (animClock > sf::seconds(1) / 20.f) {
			animClock = sf::Time::Zero;
			animIndex -= 1;
			birdSprite.setTexture(birdTex[birdSet][animIndex]);
			if (animIndex == 0) {
				animIndex = 3;
			}
		}
		deltaRotation = rotationSpeed * delta.asSeconds();
		float currentRotation = birdSprite.getRotation();
		if (currentRotation > 315 || currentRotation < 45) {
			currentRotation -= deltaRotation;
			if (currentRotation < 315 && currentRotation > 180) {
				currentRotation = 315.001;
			}

			birdSprite.setRotation(currentRotation);
		}

	}
	else { // If bird is falling, set wings to glide
		animIndex = 2;
		birdSprite.setTexture(birdTex[birdSet][animIndex]);

		deltaRotation = -rotationSpeed * delta.asSeconds();
		float currentRotation = birdSprite.getRotation();
		if (currentRotation > 315 || currentRotation < 45) {
			currentRotation -= deltaRotation;
			if (currentRotation > 45 && currentRotation < 180) {
				currentRotation = 44.999;
			}
			birdSprite.setRotation(currentRotation);
		}
	}
}