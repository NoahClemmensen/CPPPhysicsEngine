#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <math.h>

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

namespace Sin {
	static float sinRange(float a, float f, float phi, float t) {
		return a * std::sin(2 * M_PI * f * t + phi);
	}

	static int sinRange(int a, int f, int phi, int t) {
		return a * std::sin(2 * M_PI * f * t + phi);
	}
}