#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
namespace ECU {
	class InputManager {
	public:
		InputManager(){}
		~InputManager(){}

		bool IsSpriteClicked(Sprite object, Mouse::Button button, RenderWindow& window);

		Vector2i GetMousePosition(RenderWindow& window);
	};
}