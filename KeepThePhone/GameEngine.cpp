#include "stdafx.h"
#include "GameEngine.h"

GameEngine::GameEngine() : _event(&Input::_event)
{
	_windowSystem = new WindowSystem(_event);
	_sceneSystem = new SceneSystem();
	_resourceContainer = new ResContainer;

	_lag = sf::microseconds(0);
	_frame.restart();
}

GameEngine::~GameEngine()
{
	delete _resourceContainer;
	delete _sceneSystem;
	delete _windowSystem;
}

GameEngine* GameEngine::GetInstance()
{
	static std::unique_ptr<GameEngine> _instance(new GameEngine());
	return _instance.get();
}

void GameEngine::Init()
{
	srand((unsigned)time(NULL));

	_resourceContainer->Init();
	_sceneSystem->Init();
}

void GameEngine::Update()
{
	_windowSystem->Update();
	_sceneSystem->Update();
	*_event = sf::Event();
}

void GameEngine::Render()
{
	_sceneSystem->Render();
	_windowSystem->Render();
}

void GameEngine::Release()
{
	_resourceContainer->Release();
	_sceneSystem->Release();
}

int GameEngine::Run()
{
	Init();

	while (_windowSystem->isOpen())
	{
		_lag += _frame.getElapsedTime();
		_frame.restart();
		while (_lag >= sf::milliseconds(16))
		{
			Update();
			_lag -= sf::milliseconds(16);
		}

		Render();
	}

	Release();

	return 0;
}
