#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "VerletCircle.h"
#include "Math.h"

using namespace std;

class Demo : public olc::PixelGameEngine {
public:
	Demo() {
		sAppName = "Demo";
	}

private:
	float screenWidth = ScreenWidth();
	float screenHeight = ScreenHeight();

	Vec2 gravity = { 0.0f, 9.81f };
	VerletCircle circle = VerletCircle({ screenWidth, screenHeight}, 20.0f);

public:
	bool OnUserCreate() override {
		// Called once start

		return true;
	}

	bool OnUserUpdate(float DeltaTime) override {
		// Called once per frame
		Clear(olc::BLACK);

		ApplyGravity();
		ApplyConstraint();
		UpdatePositions(DeltaTime);

		circle.DrawSelf(this);

		return true;
	}

	void UpdatePositions(float DeltaTime) {
		circle.UpdatePosition(DeltaTime);
	}

	void ApplyGravity() {
		circle.Accelerate(gravity);
	}

	void ApplyConstraint() {
		Vec2 position{ screenWidth / 2, screenHeight / 2 };
		float radius = screenHeight / 2;

		Vec2 to_obj = circle.Position - position;
		float dist = Vector2Length(to_obj);

		if (dist > radius - circle.Radius) {
			Vec2 n = to_obj / dist;
			circle.Position = position + n * (dist - circle.Radius);
		}
	}
};

int main() {
	Demo demo;
	if (demo.Construct(720, 480, 1, 1)) {
		demo.Start();
	}	

	return 0;
}