#ifndef _INCLUDE_SCENENODE_H
#define _INCLUDE_SCENENODE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
	public:
		typedef	std::unique_ptr<SceneNode> Ptr;

	public:
		SceneNode();

		void attachChild(Ptr child);
		Ptr detachChild(const SceneNode& node);

		sf::Transform getWorldTransform() const;
		sf::Vector2f getWorldPosition() const;
		
		void update(sf::Time dt);

	private:
		virtual void updateCurrent(sf::Time dt);
		void updateChildren(sf::Time dt);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		std::vector<Ptr> mChildren;
		SceneNode *mParent;
};

#endif
