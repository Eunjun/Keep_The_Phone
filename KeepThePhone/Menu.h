#pragma once
#include "GameScene.h"
class Menu : public GameScene
{
	static std::once_flag _bgm;
	sf::IntRect _menuBound[3];

public:
	Menu();
	virtual ~Menu();

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

