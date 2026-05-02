#include <sstream>
#include <iostream>
#include "MainMenuState.h"
#include "GameState.h"
#include "DEFINITIONS.h"
namespace ECU {
	MainMenuState::MainMenuState(GameDataRef data) :_data(data) {

	}
	void MainMenuState::Init() {
		if (_data->buttonSoundBuffer.loadFromFile(BUTTON_SOUND_FILEPATH)) {
			_data->buttonSound.setBuffer(_data->buttonSoundBuffer);
		}
		if (_data->bgSoundBuffer.loadFromFile(BACK_GROUND_MUSIC_FILEPATH)) {
			_data->bgSound.setBuffer(_data->bgSoundBuffer);
		}
		_data->bgSound.setLoop(true);
		_data->bgSound.play();
		_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		_title.setPosition( (SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width/2),
			_title.getGlobalBounds().height/2);
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));

	}
	void MainMenuState::HandleInput() {
		Event event;
		while (_data->window.pollEvent(event)) {
			if (Event::Closed == event.type) {
				_data->window.close();
			}
			if (_data->input.IsSpriteClicked(_playButton, Mouse::Left, _data->window)) {
				_data->machine.AddState(StateRef(new GameState(_data)), true);
				_data->buttonSound.play();
				_data->bgSound.pause();
			}
		}
	}
	void MainMenuState::Update(float dt) {

	}
	void MainMenuState::Draw(float dt) {
		_data->window.clear();
		_data->window.draw(_background);
		_data->window.draw(_title);
		_data->window.draw(_playButton);
		_data->window.display();
	}
}
