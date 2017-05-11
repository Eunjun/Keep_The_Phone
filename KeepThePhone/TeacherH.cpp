#include "stdafx.h"
#include "TeacherH.h"


TeacherH::TeacherH() : GameObject(g_GameEngine->GetResContainer()->GetTexture("TeacherH"), sf::Vector2f(0, 0), sf::Vector2f(680, 500))
{
	_idx = 4;

	_laser = new Laser(LaserType::MSHLaser);

	_randIdx = false;
	_beforCheck = sf::milliseconds(700);

	_checkLength = sf::milliseconds(1500);
	_checkTime = sf::milliseconds(500);
	_minCheckTime = sf::milliseconds(1000);

	_checkInterval = sf::milliseconds(20);
}


TeacherH::~TeacherH()
{
}

void TeacherH::Init()
{
	_clock.restart();
	if (_checkLength > _minCheckTime)
	{
		_checkLength -= _checkInterval;
	}
	_checking = false;
	_randIdx = false;
	_laser->SetAlpha(0);
}

void TeacherH::Update()
{
	if (_clock.getElapsedTime() >= _beforCheck + _checkLength)
	{
		Init();
	}
	else if (_clock.getElapsedTime() >= _beforCheck + _checkLength - _checkTime)
	{
		_checking = true;
		_laser->SetAlpha(255);
	}
	else if (_clock.getElapsedTime() >= _beforCheck)
	{
		if (!_randIdx)
		{
			_idx = rand() % 5;
			_laser->SetIndex(_idx);

			_pos.y = 100 * (_idx + 1);
			_randIdx = true;
		}
		_laser->SetAlpha(127);
	}
}

void TeacherH::Render()
{
	GameObject::Render();
	_laser->Render();
}

void TeacherH::Release()
{
}