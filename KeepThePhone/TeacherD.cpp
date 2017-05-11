#include "stdafx.h"
#include "TeacherD.h"


TeacherD::TeacherD() : GameObject(g_GameEngine->GetResContainer()->GetTexture("TeacherD"), sf::Vector2f(0, 0), sf::Vector2f(120, 20))
{
	_idx = 0;

	_laser = new Laser(LaserType::DJKLaser);

	_randIdx = false;
	_checking = false;
	_beforCheck = sf::milliseconds(400);

	_checkLength = sf::milliseconds(1900);
	_checkTime = sf::milliseconds(500);
	_minCheckTime = sf::milliseconds(1100);

	_checkInterval = sf::milliseconds(50);
}


TeacherD::~TeacherD()
{
}


void TeacherD::Init()
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

void TeacherD::Update()
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

			_pos.x = 120 * (_idx + 1);
			_randIdx = true;
		}
		_laser->SetAlpha(127);
	}
}

void TeacherD::Render()
{
	GameObject::Render();
	_laser->Render();
}

void TeacherD::Release()
{
}
