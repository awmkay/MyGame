#include "Game.h"

#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	try {
		Game game;
		game.run();
	} catch (std::exception& e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}
}
