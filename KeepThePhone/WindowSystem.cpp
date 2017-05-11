#include "stdafx.h"
#include "WindowSystem.h"


WindowSystem::WindowSystem(sf::Event* _event) : _window(sf::VideoMode(WINDOW_W, WINDOW_H), "Keep The Phone"), _event(_event)
{
	_window.setFramerateLimit(60);
	_window.setKeyRepeatEnabled(false);
}

WindowSystem::~WindowSystem()
{
	_window.close();
}

void WindowSystem::Update()
{
	while (_window.pollEvent(*_event))
	{
		switch (_event->type)
		{
		case sf::Event::Closed:
			_window.close();
			break;
		case sf::Event::Resized:
			_window.setSize(sf::Vector2u(WINDOW_W, WINDOW_H));
			break;
		case sf::Event::MouseButtonReleased:
			g_GameEngine->GetResContainer()->GetMusic("KeyEffect")->play();
			break;

		default:
			break;
		}
	}
	
	_window.clear(sf::Color::White);
}

void WindowSystem::Render()
{
	_window.display();
}

