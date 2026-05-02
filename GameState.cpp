#include <sstream>
#include <iostream>
#include "GameState.h"
#include "DEFINITIONS.h"
#include "GameOverState.h"
namespace ECU {
	GameState::GameState(GameDataRef data) :_data(data) {

	}
	void GameState::Init() {
		if (!_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH)) {

		}
		if (!_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH)) {

		}
		if (_data->hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH)) {
			_data->hitSound.setBuffer(_data->hitSoundBuffer);
		}
		_wingSound.setBuffer(_wingSoundBuffer);
		_pointSound.setBuffer(_pointSoundBuffer);
		_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
		_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
		_data->assets.LoadTexture("Land", LAND_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAM_1_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAM_2_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAM_3_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAM_4_FILEPATH);
		_data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);
		_data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

		pipe = new Pipe(_data);
		land = new Land(_data);
		bird = new Bird(_data);
		flash = new Flash(_data);
		hud = new HUD(_data);
		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		_score = 0;
		hud->UpdateScore(_score);
		_gameState = GameStates::eReady;
	}
	void GameState::HandleInput() {
		Event event;
		while (_data->window.pollEvent(event)) {
			if (Event::Closed == event.type) {
				_data->window.close();
			}
			if (_data->input.IsSpriteClicked(_background, Mouse::Left, _data->window)) {
				if (GameStates::eGameOver != _gameState) {
					_gameState = GameStates::ePlaying;
					bird->Tap();
					_wingSound.play();
				}
			}
		}
	}
	void GameState::Update(float dt) {
		if (GameStates::eGameOver != _gameState) {
			bird->Animate(dt);
			land->MoveLand(dt);
		}
		if (GameStates::ePlaying == _gameState) {
			pipe->MovePipes(dt);
			if (clock.getElapsedTime().asSeconds() > pipe->GetSpawnFrequency() ) {
				pipe->RandomisePipeOffset();
				pipe->SpawnInvisiblePipe();
				pipe->SpawnBottomPipe();
				pipe->SpawnTopPipe();
				pipe->SpawnScoringPipe();
				clock.restart();
			}
			bird->Update(dt);
			vector<Sprite> landSprites = land->GetSprites();
			for (int i = 0; i < landSprites.size(); i++) {
				if (collision.CheckSpriteCollision(bird->GetSprite(), 0.1f, landSprites.at(i), 1.0f)) {
					_gameState = GameStates::eGameOver;
					clock.restart();
					_data->hitSound.play();
				}
			}
			vector<Sprite> pipeSprites = pipe->GetSprites();
			for (int i = 0; i < pipeSprites.size(); i++) {
				if (collision.CheckSpriteCollision(bird->GetSprite(),0.4f, pipeSprites.at(i),1.0f)) {
					_gameState = GameStates::eGameOver;
					clock.restart();
					_data->hitSound.play();
				}
			}
			if (GameStates::ePlaying == _gameState) {
				vector<Sprite>& scoringSprites = pipe->GetScoringSprites();
				for (int i = 0; i < scoringSprites.size(); i++) {
					if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, scoringSprites.at(i), 1.0f)) {
						_score++;
						pipe->IncreasePipeSpeed(2.0f);
						land->IncreaseLandSpeed(2.0f);
						pipe->DecreasePipeFrequency(0.005f);
						hud->UpdateScore(_score);
						scoringSprites.erase(scoringSprites.begin() + i);
						_pointSound.play();
					}
				}
			}
		}
		if (GameStates::eGameOver == _gameState) {
			flash->Show(dt);
			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS) {
				_data->machine.AddState(StateRef(new GameOverState(_data,_score)),true) ;
			}
		}
	}
	void GameState::Draw(float dt) {
		_data->window.clear();
		_data->window.draw(_background);
		pipe->DrawPipes();
		land->DrawLand();
		bird->Draw();
		flash->Draw();
		hud->Draw();
		_data->window.display();
	}
}