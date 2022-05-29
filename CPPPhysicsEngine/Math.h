#pragma once

struct Vec2 {
	float x;
	float y;

	Vec2 operator + (Vec2& i) {
		return { x + i.x, y + i.y };
	}

	Vec2 operator + (const Vec2& i) {
		return { x + i.x, y + i.y };
	}

	Vec2 operator - (Vec2& i) {
		return { x - i.x, y - i.y };
	}

	Vec2 operator - (const Vec2& i) {
		return { x - i.x, y - i.y };
	}

	Vec2 operator * (float& i) {
		return { x * i, y * i };
	}

	Vec2 operator * (Vec2& i) {
		return { x * i.x, y * i.y };
	}

	Vec2 operator += (Vec2& i) {
		return { x += i.x, y += i.y };
	}

	Vec2 operator / (const float& i) {
		return { x / i, y / i };
};

float Vector2Length(Vec2 vec) {
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}