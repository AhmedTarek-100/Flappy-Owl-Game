#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

namespace ECU {
	class Land {
	public:
		Land(GameDataRef data);
		void MoveLand(float dt);
		void DrawLand();
		const vector<Sprite>& GetSprites() const;
		void IncreaseLandSpeed(float amount);
	private:
		GameDataRef _data;
		vector<Sprite>_landSprites;
		float _currentLandSpeed;
	};
}