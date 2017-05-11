#pragma once
#include "GameScene.h"
class GameEnd :
	public GameScene
{
	sf::Clock _change;
	sf::Time _delay;

public:
	GameEnd();
	virtual ~GameEnd();

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

