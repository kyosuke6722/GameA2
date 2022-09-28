#pragma once
#include "../Base/Base.h"

class Enemy01 :public Base {
private:
	CImage m_img;
public:
	Enemy01(const CVector2D& pos);
	void Update();
	void Draw();


};