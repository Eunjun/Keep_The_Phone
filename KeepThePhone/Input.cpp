#include "stdafx.h"
#include "Input.h"


sf::Event Input::_event = sf::Event();

bool Input::IsKeyPressed()
{
	return _event.type == sf::Event::EventType::KeyPressed || _event.type == sf::Event::EventType::TextEntered;
}

bool Input::IsKeyReleased()
{
	return _event.type == sf::Event::EventType::KeyReleased;
}

bool Input::IsKeyPressed(sf::Keyboard::Key key)
{
	return IsKeyPressed() && _event.key.code == key;
}

bool Input::IsMouseLeftPressed()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool Input::IsMouseRightPressed()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Right);
}

bool Input::IsMousePressed()
{
	return _event.type == sf::Event::EventType::KeyPressed;
}

bool Input::IsMouseReleased()
{
	return _event.type == sf::Event::EventType::KeyReleased;
}

bool Input::IsMousePressed(sf::Mouse::Button button)
{
	return sf::Mouse::isButtonPressed(button);
}

void Input::SetMousePos(sf::Vector2i pos)
{
	sf::Mouse::setPosition(pos);
}

sf::Vector2i Input::GetMousePos()
{
	return sf::Mouse::getPosition(*g_GameEngine->GetWindow());
}