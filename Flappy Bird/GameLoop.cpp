#include "GameLoop.h"

GameLoop::GameLoop() {
	window.create(sf::VideoMode(288, 512), "Flappy Bird");

	window.display();
}

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

void GameLoop::processEvents() {

}

void GameLoop::update(sf::Time delta) {

}

void GameLoop::render() {

}