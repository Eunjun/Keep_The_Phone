#pragma once

class GameObject;

class GameScene
{
protected:
	sf::Sprite _background;
	std::vector<GameObject*> _objects;

public:
	GameScene();
	virtual ~GameScene();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;
};

