#include <sstream>
#include <iostream>
#include "SplashState.h"
#include "MainMenuState.h"
#include "DEFINITIONS.h"
namespace ECU{
	SplashState::SplashState(GameDataRef data) :_data(data) {

	}
	void SplashState::Init() {
		if (_data->startSoundBuffer.loadFromFile(START_MUSIC_FILEPATH)) {
			_data->startSound.setBuffer(_data->startSoundBuffer);
		}
		_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
		_data->startSound.play();
	}
	void SplashState::HandleInput() {
		Event event;
		while (_data->window.pollEvent(event)) {
			if (Event::Closed == event.type) {
				_data->window.close();
			}
		}
	}
	void SplashState::Update(float dt) {
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}
	void SplashState::Draw(float dt) {
		_data->window.clear();
		_data->window.draw(_background);
		_data->window.display();
	}
}