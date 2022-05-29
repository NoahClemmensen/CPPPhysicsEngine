#pragma once
#include "olcPixelGameEngine.h"
#include "Math.h"

using namespace olc;

class VerletCircle
{
public:
	VerletCircle(Vec2 position, float radius) {
		Position = position;
		Radius = radius;
		PositionOld = position;
	}
	float Radius;
	Vec2 Position;
	Vec2 PositionOld;
	Vec2 Acceleration;

public:
	void DrawSelf(olc::PixelGameEngine* engine) {
		vd2d pos = { Position.x, Position.y };
		engine->FillCircle(pos, Radius, olc::WHITE);
	}

	void UpdatePosition(float DeltaTime) {
		const Vec2 velocity = Position - PositionOld;

		PositionOld = Position;

		Position = Position + velocity + Acceleration * DeltaTime;

		Acceleration = {};
	}

	void Accelerate(Vec2 acc) {
		Acceleration += acc;
	}
};

