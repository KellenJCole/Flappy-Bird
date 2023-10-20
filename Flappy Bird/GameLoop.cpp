#include "GameLoop.h"

// Constructor
GameLoop::GameLoop() {
	bgTexDay.loadFromFile("Resources/background-day.png");
	bgTexNight.loadFromFile("Resources/background-night.png");

	window.create(sf::VideoMode(288, 512), "Flappy Bird");

	window.display();
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
	}
}

// Update game objects
void GameLoop::update(sf::Time delta) {

}

// Draw to window
void GameLoop::render() {
	window.clear();

	window.display();
}