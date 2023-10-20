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
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Space) {
				birdy->flap();
			}
		}
	}
}

// Update game objects
void GameLoop::update(sf::Time delta) {
	ground->update(delta);
	birdy->update(delta);
}

// Draw to window
void GameLoop::render() {
	window.clear();

	window.draw(bgSprite);
	birdy->draw();
	ground->draw();

	window.display();
}