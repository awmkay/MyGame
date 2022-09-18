#ifndef _INCLUDE_RESOURCEHOLDER_H
#define _INCLUDE_RESOURCEHOLDER_H

#include <SFML/Graphics.hpp>

namespace Textures {
	enum ID {
		Eagle, 
		Raptor, 
		Desert
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder {
	public:
		void load(Identifier id, const std::string& filename);

		template <typename Parameter>
		void load(Identifier id, const std::string& filename, const Parameter& secondParam);

		Resource& get(Identifier id);
		const Resource& get(Identifier id) const;

	private:
		void insertResource(Identifier id, std::unique_ptr<Resource> resource);

	private:
		std::map<Identifier, std::unique_ptr<Resource> > mResourceMap;
};

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
#endif
