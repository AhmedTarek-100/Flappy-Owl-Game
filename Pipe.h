#pragma once
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

namespace ECU {
	class Pipe {
	public:
		Pipe(GameDataRef data);
		void DrawPipes();
		void SpawnTopPipe();
		void SpawnBottomPipe();
		void SpawnInvisiblePipe();
		void SpawnScoringPipe();
		void MovePipes(float dt);
		void RandomisePipeOffset();
		const vector<Sprite>& GetSprites() const;
		vector<Sprite>& GetScoringSprites();
		void IncreasePipeSpeed(float amount);
		float GetSpawnFrequency()const;
		void DecreasePipeFrequency(float amount);
		void DecreasePipeGap(float amount);
	private:
		GameDataRef _data;
		vector<Sprite> pipeSprites;
		vector<Sprite> scoringPipes;
		int _landHeight;
		int _pipeSpawnYOffset;
		float _currentPipeSpeed;
		float _currentPipeFrequency;
		float _currentPipeGap;
	};
}