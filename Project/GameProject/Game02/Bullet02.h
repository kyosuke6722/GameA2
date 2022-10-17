#pragma once
#include "../Base/Base.h"
class Bullet02 : public Base {
public:
	CImage m_img;
	float m_speed;
public:
	Bullet02(int type, const CVector2D& pos, float ang, float speed);
	void Update();
	void Draw();
	void Collision(Base* b);

};