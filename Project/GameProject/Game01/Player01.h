#pragma once
#include "../Base/Base.h"

class Player01 :public Base {
private:
	CImage m_img;
public:
	Player01(const CVector2D& pos);
	void Update();
	void Draw();
	
};