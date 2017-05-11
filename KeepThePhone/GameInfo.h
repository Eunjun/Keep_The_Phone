#pragma once
#include "GameScene.h"
class GameInfo :
	public GameScene
{
	sf::Clock _scene;
	sf::Time _exitTime;
public:
	GameInfo();
	virtual ~GameInfo();

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

