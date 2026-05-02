#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"
#include <vector>
namespace ECU {
	class Bird
	{
	public:
		Bird(GameDataRef data);
		void Draw();
        void Animate (float dt);
		void Update(float dt);
		void Tap();
		const Sprite& GetSprite() const;
	private:
		GameDataRef _data;
		Sprite _birdSprite;
		vector<Texture>_animationFrames;
		unsigned int _animationIterator;
		Clock _clock;
		Clock _movementClock;
		int _birdState;
		float _rotation;
	};
}