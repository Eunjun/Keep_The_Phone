#include "stdafx.h"
#include "GameEnd.h"


GameEnd::GameEnd()
{
}


GameEnd::~GameEnd()
{
}

void GameEnd::Init()
{
	g_GameEngine->GetResContainer()->GetMusic("GameOver")->play();
	_background.setTexture(*g_GameEngine->GetResContainer()->GetTexture("BackgroundGameOver"));
	_change.restart();
	_delay = sf::seconds(5.0f);
}

void GameEnd::Update()
{
	if (_change.getElapsedTime() >= _delay)
	{
		g_GameEngine->GetSceneSystem()->ChangeScene(SceneType::SceneMenu);
	}
}

void GameEnd::Render()
{
	g_GameEngine->GetWindow()->draw(_background);
}

void GameEnd::Release()
{
	g_GameEngine->GetResContainer()->GetMusic("GameOver")->stop();
	g_GameEngine->GetResContainer()->GetMusic("MenuBgm")->play();
}
