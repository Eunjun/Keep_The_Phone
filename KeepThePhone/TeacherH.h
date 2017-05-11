#pragma once
#include "GameObject.h"
#include "Laser.h"

class TeacherH :
	public GameObject
{
	Laser* _laser;

	sf::Time _beforCheck;			/// �ٸ� �ε����� �̵��ϱ� �� �����̵Ǵ� �ð�
	sf::Time _checkLength;			/// �� �ε����� �ӹ��� �ִ� �� üũ�ð�
	sf::Time _checkTime;			/// ���� üũ�ð�

	sf::Time _checkInterval;		/// üũ�ϴ� �ð��� ������
	sf::Time _minCheckTime;			/// �ּ� ���� üũ�ð�

	sf::Clock _clock;

	bool _randIdx;
	bool _checking;
	int _idx;

public:
	TeacherH();
	virtual ~TeacherH();
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	int GetIdx() const
	{
		return _checking ? _idx : -1;
	}
};

