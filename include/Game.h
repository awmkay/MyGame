#ifndef _INCLUDE_GAME_H
#define _INCLUDE_GAME_H

#include "World.h"

#include <SFML/Graphics.hpp>

class Game : private sf::NonCopyable {
	public:
		Game();
		void run();

	private:
		void processEvents();
		void update(sf::Time deltaTime);
		void render();

		void handlePlayerInput(sf::Keyboard::Key code, bool isPressed);

	private:
		sf::RenderWindow mWindow;
		World mWorld;
		
		const sf::Time timePerFrame;
};
#endif
