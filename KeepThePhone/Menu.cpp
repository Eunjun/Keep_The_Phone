#include "stdafx.h"
#include "Menu.h"

#include "SceneSystem.h"

std::once_flag Menu::_bgm;

Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::Init()
{
	_background.setTexture(*g_GameEngine->GetResContainer()->GetTexture("BackgroundMenu"));

	_menuBound[0] = sf::IntRect(117, 270, 144, 39);
	_menuBound[1] = sf::IntRect(56, 369, 144, 39);
	_menuBound[2] = sf::IntRect(81, 465, 184, 39);
	
	std::call_once(_bgm, []()
	{
		g_GameEngine->GetResContainer()->GetMusic("MenuBgm")->setLoop(true);
		g_GameEngine->GetResContainer()->GetMusic("MenuBgm")->play();
	});
}

void Menu::Update()
{
	if (Input::IsMouseLeftPressed())
	{
		auto mousePos = Input::GetMousePos();
		
		if (_menuBound[0].contains(mousePos))
		{
			g_GameEngine->GetResContainer()->GetMusic("MenuBgm")->stop();

			g_GameEngine->GetSceneSystem()->ChangeScene(SceneType::SceneStage);
		}
		else if (_menuBound[1].contains(mousePos))
		{
			g_GameEngine->GetSceneSystem()->ChangeScene(SceneType::SceneCredit);
		}
		else if (_menuBound[2].contains(mousePos))
		{
			g_GameEngine->GetWindow()->close();
		}
	}
}

void Menu::Render()
{
	g_GameEngine->GetWindow()->draw(_background);
}

void Menu::Release()
{
}
