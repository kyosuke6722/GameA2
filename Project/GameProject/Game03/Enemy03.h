#pragma once
#include"../Base/Base.h"

class Enemy03 :public Base {
private:
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down
	};
	int m_state;
	CImage m_img;
	bool m_flip;

	void StateIdle();
	void StateAttack();
	void StateDamage();
	void StateDown();
public:
	Enemy03(const CVector2D& pos, bool flip);
	void Update();
	void Draw();
	void Collision();
};