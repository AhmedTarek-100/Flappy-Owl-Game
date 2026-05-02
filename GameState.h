#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.h"
#include "Game.h"
#include "pipe.h"
#include "Land.h"
#include "Bird.h"
#include "Collision.h"
#include "Flash.h"
#include "HUD.h"

namespace ECU {
	class GameState : public State {
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		Sprite _background;
		Pipe* pipe;
		Land* land;
		Bird* bird;
		Collision collision;
		Flash* flash;
		HUD* hud;
		Clock clock;
		int _gameState;
		int _score;
		SoundBuffer _wingSoundBuffer;
		SoundBuffer _pointSoundBuffer;
		Sound _wingSound;
		Sound _pointSound;
	};
}