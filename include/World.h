#ifndef _INCLUDE_WORLD_H
#define _INCLUDE_WORLD_H

#include "ResourceHolder.h"
#include "SceneNode.h"
#include "Aircraft.h"

#include <SFML/Graphics.hpp>
#include <array>

class World : private sf::NonCopyable {
	public:
		World(sf::RenderWindow& window);
		void update(sf::Time dt);
		void draw();

	private:
		void loadTextures();
		void buildScene();

	private:
		enum Layer {
			Background,
			Air,
			LayerCount
		};

	private:
		sf::RenderWindow& mWindow;
		sf::View mWorldView;
		TextureHolder mTextures;

		SceneNode mSceneGraph;
		std::array<SceneNode*, LayerCount> mSceneLayers;
		
		sf::FloatRect mWorldBounds;
		sf::Vector2f mSpawnPosition;
		float mScrollSpeed;
		Aircraft *mPlayerAircraft;
};

#endif
