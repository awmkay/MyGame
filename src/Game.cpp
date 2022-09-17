#include "Game.h"

Game::Game() : 
		mWindow(sf::VideoMode(640, 480), "MyGame"),
		mTexture(),
		mPlayer(),
		mIsMovingUp(false),
		mIsMovingLeft(false),
		mIsMovingDown(false),
		mIsMovingRight(false),
		TimePerFrame(sf::seconds(1.0f / 60.0f)) {
	if (!mTexture.loadFromFile("media/textures/mario.png")) {
		// Handle error
	}
	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(100.0f, 100.0f);
}

Game::~Game() {}

void Game::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen()) {
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
		}
		update(TimePerFrame);
		render();
	}
}

void Game::processEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				mWindow.close();
				break;
			default:
				break;
		}
	}
}

void Game::update(sf::Time deltaTime) {
	sf::Vector2f movement(0.0f, 0.0f);
	if (mIsMovingUp) {
		movement.y -= 1.0f;
	}

	if (mIsMovingDown) {
		movement.y += 1.0f;
	}

	if (mIsMovingLeft) {
		movement.x -= 1.0f;
	}

	if (mIsMovingRight) {
		movement.x += 1.0f;
	}

	mPlayer.move(movement * deltaTime.asSeconds());
	//mPlayer.move(movement);
}

void Game::render() {
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}


void Game::handlePlayerInput(sf::Keyboard::Key code, bool isPressed) {
	switch (code) {
		case sf::Keyboard::W:
			mIsMovingUp = isPressed;
			break;
		case sf::Keyboard::A:
			mIsMovingLeft = isPressed;
			break;
		case sf::Keyboard::S:
			mIsMovingDown = isPressed;
			break;
		case sf::Keyboard::D:
			mIsMovingRight = isPressed;
			break;
		default:
			break;
	}
}