#include "stdafx.h"
#include "GameStage.h"
#include "Student.h"

std::once_flag GameStage::_tutorial;

GameStage::GameStage()
{
}


GameStage::~GameStage()
{
}

void GameStage::Init()
{
	g_GameEngine->GetResContainer()->GetMusic("GameBgm")->play();
	_background.setTexture(*g_GameEngine->GetResContainer()->GetTexture("BackgroundGame"));

	for (int i = 1; i < 6; ++i)
	{
		for (int j = 1; j < 6; j++)
		{
			_students.push_back(new Student(sf::Vector2f(j*120, i*100)));
		}
	}

	_dj = new TeacherD();
	_h = new TeacherH();
	_phone = new Phone();
	
	_dj->Init();
	_h->Init();
	_phone->Init();

	_score.restart();

	std::call_once(_tutorial, []()
	{
		g_GameEngine->GetSceneSystem()->ChangeScene(SceneType::SceneInfo);
	});
}

void GameStage::Update()
{
	_dj->Update();
	_h->Update();
	_phone->Update();

	/// GameOver
	if (_phone->GetXIdx() == _dj->GetIdx() || _phone->GetYIdx() == _h->GetIdx())
	{
		std::cout << "살아남은 시간 : " << _score.getElapsedTime().asSeconds() << "초." << std::endl;
		g_GameEngine->GetSceneSystem()->ChangeScene(SceneType::SceneEnd);
	}

}

void GameStage::Render()
{
	g_GameEngine->GetWindow()->draw(_background);

	for (auto* element : _students) { element->Render(); }

	_dj->Render();
	_h->Render();
	_phone->Render();
}

void GameStage::Release()
{
	g_GameEngine->GetResContainer()->GetMusic("GameBgm")->stop();

	for (auto element : _students)
	{
		element->Release();
		delete element;
	}
	_students.clear();
	_phone->Release();
	_h->Release();
	_dj->Release();

	delete _phone;
	delete _h;
	delete _dj;
}
