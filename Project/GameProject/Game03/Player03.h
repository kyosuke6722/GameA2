#pragma once
#include"../Base/Base.h"

class Player03 :public Base {
private:
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
	};
	int m_state;//��ԕϐ�
	CImage m_img;
	bool m_flip;
	bool m_is_ground;//���n�t���O
	int m_attack_no;//�U���ԍ�
	int m_damage_no;//�_���[�W�ԍ�

//�e��Ԃł̋���
	void StateIdle();
	void StateAttack();
	void StateDamage();
public:
	Player03(const CVector2D& pos,bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};