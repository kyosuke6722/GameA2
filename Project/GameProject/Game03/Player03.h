#pragma once
#include"../Base/Base.h"

class Player03 :public Base {
private:
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
	};
	int m_state;//状態変数
	CImage m_img;
	bool m_flip;
	bool m_is_ground;//着地フラグ
	int m_attack_no;//攻撃番号
	int m_damage_no;//ダメージ番号

//各状態での挙動
	void StateIdle();
	void StateAttack();
	void StateDamage();
public:
	Player03(const CVector2D& pos,bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};