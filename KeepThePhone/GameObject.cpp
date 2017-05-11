#include "stdafx.h"
#include "GameObject.h"


sf::RenderWindow* GameObject::GetWindow() const
{
	return _window;
}

GameObject::GameObject(sf::Texture* texture, sf::Vector2f center, sf::Vector2f start) :
	_window(g_GameEngine->GetWindow()),
	_pos(start),
	_scale(1.0f, 1.0f),
	_center(center),
	_start(start),
	_rotate(0.f)
{
	_texture = *texture;
	_sprite = sf::Sprite(_texture);
	_sprite.setOrigin(_center);
	_sprite.setPosition(_start);
}

GameObject::~GameObject()
{
}

void GameObject::Init()
{
	_pos = _start;
	_sprite.setOrigin(_center);
	_sprite.setPosition(_pos);
}

void GameObject::Update()
{
}

void GameObject::Render()
{
	_sprite.setPosition(_pos);
	_window->draw(_sprite);
}

void GameObject::Release()
{
}
