#include "stdafx.h"
#include "Credit.h"


Credit::Credit()
{
}


Credit::~Credit()
{
}

void Credit::Init()
{
	_background.setTexture(*g_GameEngine->GetResContainer()->GetTexture("BackgroundCredit"));
}

void Credit::Update()
{
	if (Input::IsKeyPressed())
	{
		g_GameEngine->GetSceneSystem()->ChangeScene(SceneType::SceneMenu);
	}
}

void Credit::Render()
{
	g_GameEngine->GetWindow()->draw(_background);
}

void Credit::Release()
{
}
