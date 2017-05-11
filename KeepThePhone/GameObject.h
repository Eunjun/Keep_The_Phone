#pragma once

class GameObject
{
	sf::RenderWindow* _window;

protected:

	sf::Vector2f _pos;
	sf::Vector2f _scale;

	sf::Vector2f _center;
	sf::Vector2f _start;

	float _rotate;
	
	sf::Texture _texture;
	sf::Sprite _sprite;

	sf::RenderWindow* GetWindow() const;
public:
	GameObject(sf::Texture* texture, sf::Vector2f center = sf::Vector2f(0.f, 0.f), sf::Vector2f start = sf::Vector2f(0.f, 0.f));
	virtual ~GameObject();

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();
};

