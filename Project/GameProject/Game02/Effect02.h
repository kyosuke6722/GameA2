#pragma once
#include"../Base/Base.h"
class Effect02 : public Base {
private:
	CImage m_img;
public:
	Effect02(const CVector2D& pos);
	void Update();
	void Draw();
};