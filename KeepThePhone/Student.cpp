#include "stdafx.h"
#include "Student.h"


Student::Student(sf::Vector2f start) : GameObject(g_GameEngine->GetResContainer()->GetTexture("student1"), sf::Vector2f(0,0), start)
{
	int textureType = rand() % 6 + 1;	/// range [1, 6]
	std::string textureName = std::string("student" + std::to_string(textureType));

	_texture = *g_GameEngine->GetResContainer()->GetTexture(textureName);
}


Student::~Student()
{
}
