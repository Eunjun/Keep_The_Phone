#pragma once
#include "GameObject.h"
#include "Laser.h"

class TeacherH :
	public GameObject
{
	Laser* _laser;

	sf::Time _beforCheck;			/// 다른 인덱스로 이동하기 전 딜레이되는 시간
	sf::Time _checkLength;			/// 한 인덱스에 머물러 있는 총 체크시간
	sf::Time _checkTime;			/// 실제 체크시간

	sf::Time _checkInterval;		/// 체크하는 시간의 감소폭
	sf::Time _minCheckTime;			/// 최소 실제 체크시간

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

