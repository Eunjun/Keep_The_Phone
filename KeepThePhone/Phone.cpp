#include "stdafx.h"
#include "Phone.h"


Phone::Phone() : GameObject(g_GameEngine->GetResContainer()->GetTexture("Phone"), sf::Vector2f(0, 0), sf::Vector2f(385, 305)), _xIdx(2), _yIdx(2)
{
}


Phone::~Phone()
{
}

void Phone::Update()
{
	GameObject::Update();

	if (Input::IsKeyPressed(sf::Keyboard::Key::Left))
	{
		if (_xIdx > 0)
		{
			_xIdx -= 1;
			_pos.x -= 120;
		}
	}
	if (Input::IsKeyPressed(sf::Keyboard::Key::Right))
	{
		if (_xIdx < 4)
		{
			_xIdx += 1;
			_pos.x += 120;
		}
	}
	if (Input::IsKeyPressed(sf::Keyboard::Key::Up))
	{
		if (_yIdx > 0)
		{
			_yIdx -= 1;
			_pos.y -= 100;
		}
	}
	if (Input::IsKeyPressed(sf::Keyboard::Key::Down))
	{
		if (_yIdx < 4)
		{
			_yIdx += 1;
			_pos.y += 100;
		}
	}
}

