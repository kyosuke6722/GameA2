#pragma once
#include"../Base/Base.h"

class Slash03 :public Base {
private:
	CImage m_img;
	bool m_flip;
	int m_attack_no;//�U���ԍ�
public:
	Slash03(const CVector2D& pos,bool flip,int type,int attack_no);
	void Update();
	void Draw();
	int GetAttackNo() {
		return m_attack_no;
	}
};