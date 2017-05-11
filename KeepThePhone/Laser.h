#pragma once
#include "GameObject.h"

enum class LaserType
{
	DJKLaser,
	MSHLaser
};

class Laser :
	public GameObject
{
	LaserType _type;
	int _alpha;
	sf::Color _alphaFilter;
public:
	Laser(LaserType type);
	virtual ~Laser();

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void SetIndex(int idx);
	void SetAlpha(int alpha);
};

