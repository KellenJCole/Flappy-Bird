#include "GameLoop.h"

// Constructor
GameLoop::GameLoop() {
	srand(time(NULL));

	bgTexDay.loadFromFile("Resources/background-day.png");
	bgTexNight.loadFromFile("Resources/background-night.png");

	rand() % 2 == 0 ? bgSprite.setTexture(bgTexDay) : bgSprite.setTexture(bgTexNight);

	window.create(sf::VideoMode(288, 512), "Flappy Bird");

	window.display();

	ground = new Base(&window);
	birdy = new Bird(&window);
	pipe = new Pipes(&window);

	baseCollisionBox.setSize(sf::Vector2f(288, 112));
	baseCollisionBox.setPosition(0, 400);
	gameOver = true;

	readyTex.loadFromFile("Resources/message.png");
	readySprite.setTexture(readyTex);

	sf::FloatRect readySpriteBounds = readySprite.getLocalBounds();
	readySprite.setOrigin(readySpriteBounds.left + readySpriteBounds.width / 2, readySpriteBounds.top + readySpriteBounds.height / 2);
	readySprite.setPosition(144, 200);

	score = 0;
}

// Game Loop
void GameLoop::run() {
	sf::Clock gameClock;
	sf::Time dt;
	while (window.isOpen()) {
		dt = gameClock.restart();
		processEvents();
		update(dt);
		render();
	}
}

// Process user input
void GameLoop::processEvents() {
	sf::Event event;

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed) {
			if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Mouse::Left) {
				if (gameOver) {
					score = 0;
					gameOver = false;
					birdy->reset();
					pipe->reset();
				}
				else {
					birdy->flap();
				}
			}
		}
	}
}

// Update game objects
void GameLoop::update(sf::Time delta) {
	if (!gameOver) {
		ground->update(delta);
		birdy->update(delta);
		pipe->updatePipes(delta);

		// Check for collisions

		if (cd.isColliding(birdy->getCollision(), baseCollisionBox)) { // If bird hits ground
			gameOver = true;
		}

		for (auto a : pipe->getCollision()) { // If bird hits a pipe
			if (cd.isColliding(birdy->getCollision(), a)) {
				gameOver = true;
			}
		}

		for (auto b : pipe->getPointCollision()) { // If bird scores
			if (cd.isColliding(birdy->getCollision(), b)) {
				score += 1;
			}
		}
	}
}

// Draw to window
void GameLoop::render() {
	window.clear();

	window.draw(bgSprite);
	birdy->draw();
	pipe->draw();
	ground->draw();

	if (gameOver) {
		window.draw(readySprite);
	}


	window.display();
}