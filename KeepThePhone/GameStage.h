#pragma once
#include "GameScene.h"
#include "Student.h"
#include "Phone.h"
#include "TeacherD.h"
#include "TeacherH.h"

class GameStage : public GameScene
{
	static std::once_flag _tutorial;
	std::vector<Student*> _students;
	Phone* _phone;
	TeacherD* _dj;
	TeacherH* _h;

	sf::Clock _score;

public:
	GameStage();
	virtual ~GameStage();

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

};

