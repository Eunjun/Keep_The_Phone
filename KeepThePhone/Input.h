#pragma once
class Input
{
public:
	static sf::Event _event;

	static bool IsKeyPressed();
	static bool IsKeyReleased();
	static bool IsKeyPressed(sf::Keyboard::Key key);

	static bool IsMouseLeftPressed();
	static bool IsMouseRightPressed();
	static bool IsMousePressed();
	static bool IsMouseReleased();
	static bool IsMousePressed(sf::Mouse::Button button);

	static void SetMousePos(sf::Vector2i pos);
	static sf::Vector2i GetMousePos();
};

