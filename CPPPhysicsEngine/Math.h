#pragma once
#include <SFML/Graphics.hpp>

namespace MathVec2f {
	static float length(sf::Vector2f& const v) {
		return sqrt(pow(v.x, 2)+pow(v.y, 2));
	}

	static sf::Vector2f normalise(sf::Vector2f& const v) {
		return v / length(v);
	}
	
	static sf::Vector2f setLength(sf::Vector2f& const v, float l) {
		return normalise(v) * l;
	}
}