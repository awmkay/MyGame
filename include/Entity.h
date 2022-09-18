#ifndef _INCLUDE_ENTITY_H
#define _INCLUDE_ENTITY_H

#include "SceneNode.h"

#include <SFML/Graphics.hpp>
#include <vector>

class Entity : public SceneNode {
	public:
		void setVelocity(sf::Vector2f velocity);
		sf::Vector2f getVelocity() const;

	private:
		virtual void updateCurrent(sf::Time dt);

	private:
		sf::Vector2f mVelocity;
};
#endif
