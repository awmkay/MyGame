#ifndef _INCLUDE_GAME_H
#define _INCLUDE_GAME_H

#include <SFML/Graphics.hpp>

class Game {
	public:
		Game();
		~Game();
		void run();

	private:
		void processEvents();
		void update(sf::Time deltaTime);
		void render();

		void handlePlayerInput(sf::Keyboard::Key code, bool isPressed);

	private:
		sf::RenderWindow mWindow;
		sf::Texture mTexture;
		sf::Sprite mPlayer;
		bool mIsMovingUp;
		bool mIsMovingLeft;
		bool mIsMovingDown;
		bool mIsMovingRight;
		const sf::Time TimePerFrame;
};
#endif
