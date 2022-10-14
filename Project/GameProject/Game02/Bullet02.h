#pragma once
#include "../Base/Base.h"
class Bullet02 : public Base {
public:
	CImage m_img;
public:
	Bullet02(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);

};