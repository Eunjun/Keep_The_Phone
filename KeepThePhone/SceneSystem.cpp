#include "stdafx.h"
#include "SceneSystem.h"

#include "Menu.h"
#include "GameStage.h"
#include "GameEnd.h"
#include "GameInfo.h"
#include "Credit.h"

SceneSystem::SceneSystem() : _currentScene(nullptr)
{
}


SceneSystem::~SceneSystem()
{
}

void SceneSystem::Init()
{
	_currentScene = new Menu();
	_currentScene->Init();
}

void SceneSystem::Update()
{
	_currentScene->Update();
}

void SceneSystem::Render()
{
	_currentScene->Render();
}

void SceneSystem::Release()
{
	_currentScene->Release();
	delete _currentScene;
}

void SceneSystem::ChangeScene(SceneType sceneType)
{
	if (_currentScene != nullptr)
	{
		_currentScene->Release();
		delete _currentScene;
	}

	switch (sceneType)
	{
	case SceneType::SceneMenu:
		_currentScene = new Menu();
		break;
	case SceneType::SceneStage:
		_currentScene = new GameStage();
		break;
	case SceneType::SceneCredit:
		_currentScene = new Credit();
		break;
	case SceneType::SceneInfo:
		_currentScene = new GameInfo();
		break;
	case SceneType::SceneEnd:
		_currentScene = new GameEnd();
		break;
	}

	_currentScene->Init();
}
