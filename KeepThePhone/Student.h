#pragma once
#include "GameObject.h"
class Student :
	public GameObject
{
public:
	Student(sf::Vector2f start);
	virtual ~Student();
};

