#pragma once

#include "System.h"
#include "GameScene.h"

enum class SceneType
{
	SceneMenu,
	SceneStage,
	SceneCredit,
	SceneInfo,
	SceneEnd
};

class SceneSystem : public System
{
	GameScene* _currentScene;
public:
	SceneSystem();
	~SceneSystem();

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void ChangeScene(SceneType sceneType);
};

