#pragma once
#include "System.h"

class WindowSystem : public System
{
	sf::RenderWindow _window;

	sf::Event* _event;

public:
	WindowSystem(sf::Event* _event);
	~WindowSystem();

	bool isOpen()
	{
		return _window.isOpen();
	}

	sf::RenderWindow* GetWindow()
	{
		return &_window;
	}
	
	void Update() override;
	void Render() override;
};
