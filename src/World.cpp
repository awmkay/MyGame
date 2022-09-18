#include "World.h"
#include "SpriteNode.h"

World::World(sf::RenderWindow& window) : 
		mWindow(window),
		mWorldView(window.getDefaultView()),
		mTextures(),
		mSceneGraph(),
		mWorldBounds({0, 0}, {mWorldView.getSize().x, 2000}),
		mSpawnPosition({mWorldView.getSize().x / 2.0f, mWorldBounds.height - mWorldView.getSize().y / 2.0f}),
		mScrollSpeed(-50.0f),
		mPlayerAircraft(nullptr) {
	loadTextures();
	buildScene();

	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt) {
	mWorldView.move(0.0f, mScrollSpeed * dt.asSeconds());

	sf::Vector2f position = mPlayerAircraft->getPosition();
	sf::Vector2f velocity = mPlayerAircraft->getVelocity();

	if (position.x <= mWorldBounds.left + 150 || position.x >= mWorldBounds.width - 150) {
		velocity.x = -velocity.x;
		mPlayerAircraft->setVelocity(velocity);
	}

	mSceneGraph.update(dt);
}

void World::draw() {
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

void World::loadTextures() {
	mTextures.load(Textures::Eagle, "media/textures/eagle.png");
	mTextures.load(Textures::Raptor, "media/textures/raptor.png");
	mTextures.load(Textures::Desert, "media/textures/desert.png");
}

void World::buildScene() {
	for (size_t layerNum = 0; layerNum < LayerCount; layerNum++) {
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[layerNum] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	sf::Texture& texture = mTextures.get(Textures::Desert);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true);

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Eagle, mTextures));
	mPlayerAircraft = leader.get();
	mPlayerAircraft->setPosition(mSpawnPosition);
	mPlayerAircraft->setVelocity({40.0f, mScrollSpeed});
	mSceneLayers[Air]->attachChild(std::move(leader));

	std::unique_ptr<Aircraft> leftEscort(new Aircraft(Aircraft::Raptor, mTextures));
	leftEscort->setPosition(-80.0f, 50.0f);
	mPlayerAircraft->attachChild(std::move(leftEscort));

	std::unique_ptr<Aircraft> rightEscort(new Aircraft(Aircraft::Raptor, mTextures));
	rightEscort->setPosition(-80.0f, 50.0f);
	mPlayerAircraft->attachChild(std::move(rightEscort));
}
