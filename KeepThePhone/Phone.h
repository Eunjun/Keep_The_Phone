#pragma once
#include "GameObject.h"
class Phone : public GameObject
{
	int _xIdx;
	int _yIdx;
public:
	Phone();
	virtual ~Phone();

	void Update() override;

	int GetXIdx() const
	{
		return _xIdx;
	}
	int GetYIdx() const
	{
		return _yIdx;
	}
};

