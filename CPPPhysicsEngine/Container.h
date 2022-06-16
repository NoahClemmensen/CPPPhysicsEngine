#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <algorithm>
#include "Geometry.h"

namespace con {
	class Container
	{
	public:
		std::vector<sf::Drawable*> Drawables;
		std::vector<sf::Texture*> Textures;
		std::vector<sf::Sound*> Sounds;

		std::vector<geo::Circle*> Circles;
		std::vector<geo::CircleConstraint*> CircleConstraints;

		Container() = default;

		void Add(sf::Drawable* obj) {
			Drawables.push_back(obj);
		}

		void Add(sf::Texture* tex) {
			Textures.push_back(tex);
		}

		void Add(sf::Sound* sound) {
			Sounds.push_back(sound);
		}

		void Add(geo::Circle* cir) {
			Circles.push_back(cir);
			Drawables.push_back(cir);
		}

		void Add(geo::CircleConstraint* con) {
			CircleConstraints.push_back(con);
			Drawables.push_back(con);
		}

		void Remove(sf::Drawable* obj) {
			Drawables.erase(std::remove(Drawables.begin(), Drawables.end(), obj));
		}

		void Remove(sf::Texture* tex) {
			Textures.erase(std::remove(Textures.begin(), Textures.end(), tex));
		}

		void Remove(sf::Sound* sound) {
			Sounds.erase(std::remove(Sounds.begin(), Sounds.end(), sound));
		}

		void Remove(geo::Circle* cir) {
			Circles.erase(std::remove(Circles.begin(), Circles.end(), cir));
		}
	};
}