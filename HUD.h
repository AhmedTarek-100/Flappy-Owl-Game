#pragma once
#include <SFML/Graphics.hpp>
#include"DEFINITIONS.h"
#include"Game.h"

namespace ECU {
	class HUD {
	public:
		HUD(GameDataRef data);
		void Draw();
		void UpdateScore(int score);

	private:
		GameDataRef _data;
		Text _scoreText;
	};
}