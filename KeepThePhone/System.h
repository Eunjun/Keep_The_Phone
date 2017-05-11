#pragma once


/**
 * \brief System Interface.
 */
class System
{
public:
	System(){}
	virtual ~System(){}
	virtual void Init() {}
	virtual void Update() {}
	virtual void Render() {}
	virtual void Release() {}

};
