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
}