#include "Entity.h"

void Entity::setVelocity(sf::Vector2f velocity) {
	mVelocity = velocity;
}

sf::Vector2f Entity::getVelocity() const {
	return mVelocity;
}

void Entity::updateCurrent(sf::Time dt) {
	move(mVelocity * dt.asSeconds());
}
