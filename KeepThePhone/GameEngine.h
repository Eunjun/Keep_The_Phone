#pragma once

#include "ResContainer.h"

#include "WindowSystem.h"
#include "SceneSystem.h"
#include "Input.h"

class GameEngine : System
{
	GameEngine();

	sf::Event* _event;

	sf::Clock _frame;
	sf::Time _lag;

	WindowSystem* _windowSystem;
	SceneSystem* _sceneSystem;
	ResContainer* _resourceContainer;

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

public:
	~GameEngine();

	static GameEngine* GetInstance();

	sf::RenderWindow* GetWindow()
	{
		return _windowSystem->GetWindow();
	}

	SceneSystem* GetSceneSystem()
	{
		return _sceneSystem;
	}

	ResContainer* GetResContainer()
	{
		return _resourceContainer;
	}

	int Run();
};

#define g_GameEngine GameEngine::GetInstance()
