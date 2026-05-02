#include "Pipe.h"

namespace ECU {
	Pipe::Pipe(GameDataRef data) :_data(data) {
		_landHeight = _data->assets.GetTexture("Land").getSize().y;
		_pipeSpawnYOffset = 0;
		_currentPipeSpeed = PIPE_MOVEMENT_SPEED;
		_currentPipeFrequency = PIPE_SPAWN_FREQUENCY;
		_currentPipeGap = 250.0f;
	}
	void Pipe::DecreasePipeGap(float amount) {
		_currentPipeGap -= amount;
		float MIN_GAP = 90.0f;
		if (_currentPipeGap < MIN_GAP) {
			_currentPipeGap = MIN_GAP;
		}
	}
	void Pipe::IncreasePipeSpeed(float amount) {
		_currentPipeSpeed += amount;
		float maxPipeSpeed = 450.0f;
		if (_currentPipeSpeed > maxPipeSpeed) {
			_currentPipeSpeed = maxPipeSpeed;
		}
	}
	float Pipe::GetSpawnFrequency() const {
		return _currentPipeFrequency;
	}
	
	void Pipe::DecreasePipeFrequency(float amount) {
		_currentPipeFrequency -= amount;
		float MIN_SPAWN_TIME = 0.8f;
		if (_currentPipeFrequency < MIN_SPAWN_TIME)
			_currentPipeFrequency = MIN_SPAWN_TIME;
	}
	void Pipe::SpawnTopPipe() {
		Sprite sprite(_data->assets.GetTexture("Pipe Down"));
		sprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffset);
		pipeSprites.push_back(sprite);
	}
		
	void Pipe::SpawnBottomPipe() {
		Sprite sprite(_data->assets.GetTexture("Pipe Up"));
		float topPipeBottomEdge = _data->assets.GetTexture("Pipe Down").getSize().y - _pipeSpawnYOffset;
		sprite.setPosition(_data->window.getSize().x, topPipeBottomEdge + _currentPipeGap);
		pipeSprites.push_back(sprite);
	}
	void Pipe::SpawnInvisiblePipe() {
		Sprite sprite(_data->assets.GetTexture("Pipe Down"));
		float topPipeBottomEdge = _data->assets.GetTexture("Pipe Down").getSize().y - _pipeSpawnYOffset;
		sprite.setPosition(_data->window.getSize().x, topPipeBottomEdge + _currentPipeGap);
		sprite.setColor(Color(0, 0, 0, 0));
		pipeSprites.push_back(sprite);
	}
	void Pipe::SpawnScoringPipe() {
		Sprite sprite(_data->assets.GetTexture("Scoring Pipe"));
		sprite.setPosition(_data->window.getSize().x, 0);
		scoringPipes.push_back(sprite);
	}
	void Pipe::MovePipes(float dt) {
		for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
			if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width) {
				pipeSprites.erase(pipeSprites.begin() + i);
			}
			else {
				float movement = _currentPipeSpeed * dt;
				pipeSprites.at(i).move(-movement, 0);
			}
		}
		for (unsigned short int i = 0; i < scoringPipes.size(); i++) {
			if (scoringPipes.at(i).getPosition().x < 0 - scoringPipes.at(i).getGlobalBounds().width) {
				scoringPipes.erase(scoringPipes.begin() + i);
			}
			else {
				float movement = _currentPipeSpeed * dt;
				scoringPipes.at(i).move(-movement, 0);
			}
		}
	}
	void Pipe::DrawPipes() {
		for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
			_data->window.draw(pipeSprites.at(i));
		}
	}
	void Pipe::RandomisePipeOffset() {
		int offsetMin = 70;
		int offsetMax = _data->window.getSize().y - _landHeight - 150;
		_pipeSpawnYOffset = rand() % (offsetMax - offsetMin + 1) + offsetMin;
	}
	const vector<Sprite>& Pipe::GetSprites() const {
		return pipeSprites;
	}
	vector<Sprite>& Pipe::GetScoringSprites(){
		return scoringPipes;
	}
}