#pragma once
#include <SFML/Graphics.hpp>

namespace geo {
	class Circle : public sf::CircleShape {
	public:
		sf::Vector2f Position;
		sf::Vector2f PositionOld;
		sf::Vector2f Acceleration;
		sf::Color Color;
		float Radius;

		Circle(float radius, sf::Vector2f position, sf::Color color, size_t points) : CircleShape(radius, points), Position(position), Radius(radius), Color(color) {
			setRadius(Radius);
			setPosition(Position);
			setFillColor(color);
			setOrigin({ Radius, Radius });
		}

		void UpdatePosition(float DeltaTime) {
			sf::Vector2f velocity = Position - Position;
			PositionOld = Position;
			Position = Position + velocity + Acceleration;
			Acceleration = {};
		}

		void Accelerate(sf::Vector2f acc) {
			Acceleration += acc;
		}
	};
}