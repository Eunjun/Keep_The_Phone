#include "stdafx.h"
#include "Laser.h"


Laser::Laser(LaserType type) : GameObject(g_GameEngine->GetResContainer()->GetTexture(type == LaserType::DJKLaser ? "DJ_KLaser":"MSHLaser")), _type(type)
{
	_alpha = 255;
	_alphaFilter = sf::Color(255, 255, 255, 255);
}


Laser::~Laser()
{
}

void Laser::Init()
{
}

void Laser::Update()
{
	GameObject::Update();
}

void Laser::Render()
{
	_alphaFilter.a = _alpha;
	_sprite.setColor(_alphaFilter);

	GameObject::Render();
}

void Laser::Release()
{
}

void Laser::SetIndex(int idx)
{
	if (_type == LaserType::DJKLaser)
	{
		_pos = sf::Vector2f((idx + 1) * 120, 100);
	}
	else
	{
		_pos = sf::Vector2f(120, (idx + 1) * 100);
	}
}

void Laser::SetAlpha(int alpha)
{
	_alpha = alpha;
}
