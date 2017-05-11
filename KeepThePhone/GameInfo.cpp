#include "stdafx.h"
#include "GameInfo.h"


GameInfo::GameInfo()
{
}


GameInfo::~GameInfo()
{
}

void GameInfo::Init()
{
	_background.setTexture(*g_GameEngine->GetResContainer()->GetTexture("BackgroundTutorial"));
	_scene.restart();
	_exitTime = sf::seconds(3.0f);
}

void GameInfo::Update()
{
	/// 3sec after change game scene
	if (_scene.getElapsedTime() >= _exitTime)
	{
		g_GameEngine->GetSceneSystem()->ChangeScene(SceneType::SceneStage);
	}
}

void GameInfo::Render()
{
	g_GameEngine->GetWindow()->draw(_background);
}

void GameInfo::Release()
{
}
