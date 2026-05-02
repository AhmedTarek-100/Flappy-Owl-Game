#include "HUD.h"
#include <string>

namespace ECU {
	HUD::HUD(GameDataRef data):_data(data) {
		_scoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_scoreText.setString("0");
		_scoreText.setCharacterSize(80);
		_scoreText.setFillColor(Color(255, 223, 0));
		_scoreText.setOrigin(_scoreText.getGlobalBounds().width/2, _scoreText.getGlobalBounds().height/2);
		_scoreText.setPosition(_data->window.getSize().x/2 - 10 , _data->window.getSize().y/15);
	}
	void HUD::Draw(){
		_data->window.draw(_scoreText);
	}
	void HUD::UpdateScore(int score) {
		_scoreText.setString(to_string(score));
	}
}