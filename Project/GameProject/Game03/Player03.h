#pragma once
#include"../Base/Base.h"

class Player03 :public Base {
private:
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down
	};
	int m_state;//状態変数
	CImage m_img;
	bool m_flip;
//各状態での挙動
	void StateIdle();
	void StateAttack();
	void StateDamage();
	void StateDown();
public:
	Player03(const CVector2D& pos,bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};