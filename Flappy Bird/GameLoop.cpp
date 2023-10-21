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
	scoreObj = new Score(&window);

	baseCollisionBox.setSize(sf::Vector2f(288, 112));
	baseCollisionBox.setPosition(0, 400);
	gameOver = true;
	gameOverScreen = false;

	readyTex.loadFromFile("Resources/message.png");
	readySprite.setTexture(readyTex);

	gameOverTex.loadFromFile("Resources/gameover.png");
	gameOverSprite.setTexture(gameOverTex);


	sf::FloatRect readySpriteBounds = readySprite.getLocalBounds();
	readySprite.setOrigin(readySpriteBounds.left + readySpriteBounds.width / 2, readySpriteBounds.top + readySpriteBounds.height / 2);
	readySprite.setPosition(144, 200);

	sf::FloatRect gameOverSpriteBounds = gameOverSprite.getLocalBounds();
	gameOverSprite.setOrigin(gameOverSpriteBounds.left + gameOverSpriteBounds.width / 2, gameOverSpriteBounds.top + gameOverSpriteBounds.height / 2);
	gameOverSprite.setPosition(144, 200);

	score = 0;
	scoreObj->setScore(score);

	scoreBuffer.loadFromFile("Resources/point.wav");
	collisionBuffer.loadFromFile("Resources/hit.wav");

	scoreSound.setBuffer(scoreBuffer);
	collisionSound.setBuffer(collisionBuffer);

	timeSinceScored = sf::Time::Zero;
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
				if (gameOver && !gameOverScreen) {
					score = 0;
					scoreObj->setScore(0);
					gameOver = false;
				}
				else if (gameOverScreen) {
					gameOverScreen = false;
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
	timeSinceScored += delta;

	if (!gameOver) {
		ground->update(delta);
		birdy->update(delta);
		pipe->updatePipes(delta);

		// Check for collisions

		if (cd.isColliding(birdy->getCollision(), baseCollisionBox)) { // If bird hits ground
			collisionSound.play();
			gameOver = true;
			gameOverScreen = true;
		}

		for (auto a : pipe->getCollision()) { // If bird hits a pipe
			if (cd.isColliding(birdy->getCollision(), a)) {
				collisionSound.play();
				gameOver = true;
				gameOverScreen = true;
			}
		}

		for (auto b : pipe->getPointCollision()) { // If bird scores
			if (cd.isColliding(birdy->getCollision(), b)) {
				if (timeSinceScored > sf::seconds(1)) {
					timeSinceScored = sf::Time::Zero;
					scoreSound.play();
					score += 1;
					scoreObj->setScore(score);
				}
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

	if (!gameOver || gameOverScreen) {
		scoreObj->draw();
	}

	if (gameOver && !gameOverScreen) {
		window.draw(readySprite);
	}
	else if (gameOverScreen) {
		window.draw(gameOverSprite);
	}


	window.display();
}