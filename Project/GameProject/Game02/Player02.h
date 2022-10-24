#pragma once
#include "../Base/Base.h"
class Player02 : public Base {
public:
	CImage m_img;
	int m_cnt;
public:
	Player02(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};