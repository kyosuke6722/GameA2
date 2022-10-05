#pragma once
#include "../Base/Base.h"

class Ball01 :public Base {
private:
	CImage m_img;
public:
	Ball01(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base*b);
};

