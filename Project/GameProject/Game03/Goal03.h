#pragma once
#include"../Base/Base.h"

class Goal03 :public Base {
private:
	CImage m_img;
public:
	Goal03(const CVector2D& pos);
	void Draw();
};