#pragma once
#include "GameScene.h"
class Credit :
	public GameScene
{
public:
	Credit();
	virtual ~Credit();

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

